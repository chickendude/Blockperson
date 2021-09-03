#include "game.h"
#include "constants.h"
#include "levels.h"

//------------------------------------------------------------------------------
// Constants and macros
//------------------------------------------------------------------------------
#define TILE(n) (n * 4)
#define MOVED_R(x1, x2) x1 > x2 && ((x1 & 0xf) < (x2 & 0xf))
#define MOVED_L(x1, x2) x1 < x2 && ((x1 & 0xf) > (x2 & 0xf))
#define MOVED_D(y1, y2) y1 > y2 && ((y1 & 0xf) < (y2 & 0xf))
#define MOVED_U(y1, y2) y1 < y2 && ((y1 & 0xf) > (y2 & 0xf))

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------
void draw_tile(int x, int y, int tile_id);

void draw_column(int map_x, int map_y, int sb_x, const Level *level);

void draw_row(int map_x, int map_y, int sb_y, const Level *level);

// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void draw_tilemap(Game *game)
{
    return;
    int max_x, max_y, start_x, start_y;
    const Level *level = game->cur_level;
    const char *map = game->cur_level->tilemap;

    // Erase everything that was here just for good measure
    se_fill(&se_mem[30][0], 0);

    // Find the starting tilemap position (16 pixel aligned)
    start_x = game->camera.x / TILE_SIZE;
    start_y = game->camera.y / TILE_SIZE;

    // If the tilemap dimensions are smaller than the screen block, make sure we
    // don't draw data outside the tilemap
    max_x = SB_COLS < level->w ? SB_COLS : level->w;
    max_y = SB_ROWS < level->h ? SB_ROWS : level->h;
    for (int x = 0; x < max_x; x++)
    {
        for (int y = 0; y < max_y; y++)
        {
            switch (map[(y + start_y) * level->w + (x + start_x)])
            {
                case 'B':
                    draw_tile(x, y, TILE(1));
                    break;
                case 'D':
                    draw_tile(x, y, TILE(2));
                    break;
                case 'O':
                    game->blocks[game->num_blocks].x =
                            (x + start_x) * TILE_SIZE;
                    game->blocks[game->num_blocks].y =
                            (y + start_y) * TILE_SIZE;
                    game->num_blocks++;
                    break;
            }
        }
    }
}

/**
 * When cam.x < prev_cam.x we are moving left
 * @param game
 */
void update_tilemap(Game *game)
{
    Camera *cam = &game->camera;
    Camera *prev_cam = &game->prev_camera;
    int map_x = cam->x / TILE_SIZE;
    int map_y = cam->y / TILE_SIZE;
    int cur_x = cam->x;
    int cur_y = cam->y;
    int prev_x = prev_cam->x;
    int prev_y = prev_cam->y;

    // Check if moved right a tile
    if (MOVED_R(cur_x, prev_x))
    {
        // The column to the left of the leftmost column (0 - 1 -> 31)
        int x = (map_x - 1) & 31;
        draw_column(map_x + SB_COLS - 1, map_y, x, game->cur_level);
    } else if (MOVED_L(cur_x, prev_x))
    {
        int x = (map_x) & 31;
        draw_column(map_x, map_y, x, game->cur_level);
//        draw_column(x, map_x, game->cur_level);
    }

    if (MOVED_D(cur_y, prev_y))
    {
        int y = (map_y + 10) & 15;
        draw_row(map_x, map_y + 10, y, game->cur_level);
    } else if (MOVED_U(cur_y, prev_y))
    {
        int y = (map_y) & 15;
        draw_row(map_x, map_y, y, game->cur_level);
    }
    game->prev_camera = game->camera;
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------
inline void draw_tile(int x, int y, int tile_id)
{
    // Drawing to screen block base 30
    int sbb = 30;

    // Tiles are 16x16, but are stored in VRAM as 8x8 pixel sprites
    x *= TILE_SIZE / 8;
    y *= NUM_TILES_IN_ROW * TILE_SIZE / 8;

    // Load tiles into the screen block
    se_mem[sbb][y + x] = tile_id;
    se_mem[sbb][y + x + 1] = tile_id + 1;
    se_mem[sbb][y + NUM_TILES_IN_ROW + x] = tile_id + 2;
    se_mem[sbb][y + NUM_TILES_IN_ROW + x + 1] = tile_id + 3;
}

void draw_column(int map_x, int map_y, int sb_x, const Level *level)
{
    int tile_id;
    char *map = &level->tilemap[map_y * level->w + map_x];
    int max_y = SB_ROWS < level->h ? SB_ROWS : level->h;
    for (int y = 0; y < 11; y++)
    {
        switch (*map)
        {
            case 'B':
                tile_id = TILE(1);
                break;
            case 'D':
                tile_id = TILE(2);
                break;
            default:
                tile_id = TILE(0);
        }
        draw_tile(sb_x, (map_y + y) & 31, tile_id);

        // Advance to the next row in tile map
        map += level->w;
    }
}

void draw_row(int map_x, int map_y, int sb_y, const Level *level)
{
    int tile_id;
    char *map = &level->tilemap[(map_y * level->w) + map_x];
    int max_x = SB_COLS < level->w ? SB_COLS : level->w;
    for (int x = 0; x < 16; x++)
    {
        switch (*map++)
        {
            case 'B':
                tile_id = TILE(1);
                break;
            case 'D':
                tile_id = TILE(2);
                break;
            default:
                tile_id = TILE(0);
        }
        draw_tile(x, sb_y, tile_id);
    }
}
