#include "game.h"
#include "constants.h"
#include "levels.h"
// Tile data
#include "bg.h"

//------------------------------------------------------------------------------
// Constants and macros
//------------------------------------------------------------------------------
#define TILE(n) (n * 4)
#define MOVED_R(x1, x2) (x1 > x2 && ((x1 & 0xf) < (x2 & 0xf)))
#define MOVED_L(x1, x2) (x1 < x2 && ((x1 & 0xf) > (x2 & 0xf)))
#define MOVED_D(y1, y2) (y1 > y2 && ((y1 & 0xf) < (y2 & 0xf)))
#define MOVED_U(y1, y2) (y1 < y2 && ((y1 & 0xf) > (y2 & 0xf)))

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
    int start_x, start_y;
    const Level *level = game->cur_level;
    const char *map = game->cur_level->tilemap;

    // Erase everything that was here just for good measure
    se_fill(&se_mem[30][0], 0);

    // Find the starting tilemap position (16 pixel aligned)
    start_x = game->camera.x / TILE_SIZE;
    start_y = game->camera.y / TILE_SIZE;

    for (int x = start_x; x < start_x + SB_COLS; x++)
    {
        for (int y = start_y; y < start_y + SB_ROWS; y++)
        {
            switch (map[y * level->w + x])
            {
                case 'B':
                    draw_tile(x & 31, y & 31, TILE(1));
                    break;
                case 'D':
                    draw_tile(x, y, TILE(2));
                    break;
            }
        }
    }
}

void draw_bg_tilemap() {
    unsigned char tile_id = 22;
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            tile_id = bgMap[j * 32 + i] * 4 + 12;
            int sbb = 28;
            int x = i * 2;
            int y = j * 2;
            if (x >= 32)
            {
                sbb++;
                x -= 32;
            }
            se_mem[sbb][y * NUM_TILES_IN_ROW + x] = tile_id;
            se_mem[sbb][y * NUM_TILES_IN_ROW + x + 1] = tile_id + 1;
            se_mem[sbb][(y + 1) * NUM_TILES_IN_ROW + x] = tile_id + 2;
            se_mem[sbb][(y + 1) * NUM_TILES_IN_ROW + x + 1] = tile_id + 3;
        }
    }
}

void extract_tilemap(Game *game)
{
    const Level *level = game->cur_level;
    const char *map = game->cur_level->tilemap;

    for (int x = 0; x < level->w; x++)
    {
        for (int y = 0; y < level->h; y++)
        {
            switch (map[y * level->w + x])
            {
                case 'O':
                    game->blocks[game->num_blocks].x = x * TILE_SIZE;
                    game->blocks[game->num_blocks].y = y * TILE_SIZE;
                    game->num_blocks++;
                    break;
                case 'M':
                    game->player.x = x * TILE_SIZE;
                    game->player.y = y * TILE_SIZE;
                    break;
            }
        }
    }
}

void update_tilemap(Game *game)
{
    Camera *cam = &game->camera;
    Camera *prev_cam = &game->prev_camera;
    int map_x = cam->x / TILE_SIZE;
    int map_y = cam->y / TILE_SIZE;

    // Check if moved right or left a tile
    if (MOVED_R(cam->x, prev_cam->x))
    {
        // The column to the left of the leftmost column (0 - 1 -> 31)
        int x = (map_x - 1) & 31;
        draw_column(map_x + SB_COLS - 1, map_y, x, game->cur_level);
    } else if (MOVED_L(cam->x, prev_cam->x))
    {
        int x = (map_x) & 31;
        draw_column(map_x, map_y, x, game->cur_level);
    }

    // Check if moved up or down a tile
    if (MOVED_D(cam->y, prev_cam->y))
    {
        int sb_y = (map_y + 10);
        draw_row(map_x, map_y + 10, sb_y, game->cur_level);
    } else if (MOVED_U(cam->y, prev_cam->y))
    {
        int y = (map_y) & 15;
        draw_row(map_x, map_y, y, game->cur_level);
    }
    game->prev_camera = game->camera;
}

bool
is_blocked(int map_x, int map_y, const Level *level, Block *blocks,
           int num_blocks)
{
    // Check if tilemap is passable
    if (level->tilemap[map_y * level->w + map_x] == 'B')
        return true;

    // Check if there is a block at this coordinate
    return get_block(map_x, map_y, blocks, num_blocks) != NULL;
}

bool reached_door(Game *game)
{
    int map_x, map_y, map_w;
    Player *player = &game->player;
    char *map = game->cur_level->tilemap;

    map_x = player->x / TILE_SIZE;
    map_y = player->y / TILE_SIZE;
    map_w = game->cur_level->w;
    return map[map_y * map_w + map_x] == 'D';
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------
inline void draw_tile(int x, int y, int tile_id)
{
    // Drawing to screen block base 30
    int sbb = 30;

    // Tiles are 16x16, but are stored in VRAM as 8x8 pixel sprites
    // 1. Make sure coordinates fit within 0-15
    // 2. x: Multiply by two since each 16x16 tile is actually a 2x2 set of 8x8
    //       sprites.
    //    y: Similar to x, but we also need to make sure it skips to the next
    //       row in the screen block.
    x &= 15;
    y &= 15;
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
    char *map;

    // Grab the starting address in the map
    map = &level->tilemap[map_y * level->w + map_x];

    // 10 16x16 rows fit on screen, + 1 for the offscreen tile when scrolling
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
    for (int x = 0; x < SB_COLS; x++)
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
        draw_tile(x + map_x, sb_y, tile_id);
    }
}
