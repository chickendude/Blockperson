#include <tonc.h>
#include "constants.h"
#include "game.h"
#include "levels.h"
#include "maps.h"
#include "objects.h"
// Sprite data
#include "tiles.h"

#define TILE(n) (n * 4 + 1)

/**
 * Initialize game data.
 *
 * Prepare background registers, load sprites and tiles, etc.
 */
void initialize(Game *game);

/** Main game loop. */
_Noreturn void play(Game *game);

//------------------------------------------------------------------------------
// Program entry point
//------------------------------------------------------------------------------

void draw_tile(int x, int y, int tile_id)
{
    x *= TILE_SIZE / 8;
    y *= NUM_TILES_IN_ROW * TILE_SIZE / 8;
    int sbb = 30;
    se_mem[sbb][y + ((x) & 31)] = tile_id;
    se_mem[sbb][y + ((x + 1) & 31)] = tile_id + 1;
    se_mem[sbb][y + NUM_TILES_IN_ROW + ((x) & 31)] = tile_id + 2;
    se_mem[sbb][y + NUM_TILES_IN_ROW + ((x + 1) & 31)] = tile_id + 3;
}

void draw_tilemap(const Map *map, int start_x, int start_y)
{
    se_fill(&se_mem[30][0], 0);
    se_fill(&se_mem[31][0], 0);
    start_x /= TILE_SIZE;
    start_y /= TILE_SIZE;
    for (int x = 0; x < (256 / TILE_SIZE); x++)
    {
        for (int y = 0; y < (256 / TILE_SIZE); y++)
        {
            switch (map->tilemap[(y + start_y) * 20 + (x + start_x)])
            {
                case 'B':
                    draw_tile(x, y, TILE(0));
                    break;
                case 'D':
                    // tile id 2, 4 sprites per tile (16x16), skip first
                    // (empty) tile
                    draw_tile(x, y, TILE(2));
                    break;
            }
        }
    }
}


int main(void)
{
    Game game;
    initialize(&game);
    play(&game);
    return 0;
}

void initialize(Game *game)
{
    load_level(game, &level_1);

    // Copy tile and palette data
    memcpy32(&tile_mem[0][1], tilesTiles, tilesTilesLen / 4);
    memcpy32(pal_bg_mem, tilesPal, tilesPalLen / 4);

    draw_tilemap(game->cur_level->map, game->camera.x, game->camera.y);

    // Enable Mode 0: 4 bgs available, but none can be rotated
    REG_DISPCNT = DCNT_MODE0 | DCNT_BG0;

    // Tiles should be at the first character block, maps should be in the last
    // Screen block
    REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_REG_64x32;
}

_Noreturn void play(Game *game)
{
//    int sx = 0;
//    int sy = 0;
    Camera *camera = &game->camera;
    const Level *level = game->cur_level;

    while (1)
    {
        vid_vsync();
        REG_BG0HOFS = camera->x % 16;
        REG_BG0VOFS = camera->y % 16;
        draw_tilemap(level->map, camera->x, camera->y);

        key_poll();
        camera->x += key_tri_horz() * GAME_SPEED;
        if (camera->x < 0) camera->x = 0;
        if (camera->x > level->map->w * 16 - SCREEN_WIDTH) camera->x = 20 * 16 - SCREEN_WIDTH;
        camera->y += key_tri_vert() * GAME_SPEED;
        if (camera->y < 0) camera->y = 0;
        if (camera->y > 8 * 16 - SCREEN_HEIGHT) camera->y = 8 * 16 - SCREEN_HEIGHT;
    };
}