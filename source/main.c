#include <tonc.h>
#include "constants.h"
#include "game.h"
#include "levels.h"
// Sprite data
#include "tiles.h"

// TODO: Only update edges of tilemap
// TODO: Add player to screen
// TODO: Add second background for parallax scrolling
// TODO: Update camera to follow player
// TODO: Pick up blocks

// Buffer to hold changes to OAM data so that you can update outside of VBLANK.
// This will be copied over to OAM in VBLANK.
OBJ_ATTR obj_buffer[NUM_SPRITES];

/**
 * Initialize game data.
 *
 * Prepare background registers, load sprites and tiles, etc.
 */
void initialize(Game *game);

/** Main game loop. */
_Noreturn void play(Game *game);

//------------------------------------------------------------------------------
// Constants and macros
//------------------------------------------------------------------------------
#define TILE(n) (n * 4 + 1)

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

void draw_tilemap(Game *game, int start_x, int start_y)
{
    const char *map = game->cur_level->tilemap;
    game->num_blocks = 0;
    se_fill(&se_mem[30][0], 0);
    se_fill(&se_mem[31][0], 0);
    start_x /= TILE_SIZE;
    start_y /= TILE_SIZE;
    for (int x = 0; x < (256 / TILE_SIZE); x++)
    {
        for (int y = 0; y < (256 / TILE_SIZE); y++)
        {
            switch (map[(y + start_y) * 20 +
                        (x + start_x)])
            {
                case 'B':
                    draw_tile(x, y, TILE(0));
                    break;
                case 'D':
                    // tile id 2, 4 sprites per tile (16x16), skip first
                    // (empty) tile
                    draw_tile(x, y, TILE(2));
                    break;
                case 'O':
                    game->blocks[game->num_blocks].x = (x + start_x) * TILE_SIZE;
                    game->blocks[game->num_blocks].y = (y + start_y) * TILE_SIZE;
                    game->num_blocks++;
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
    memcpy32(&tile_mem[4][1], tilesTiles, tilesTilesLen / 4);
    memcpy32(pal_obj_mem, tilesPal, tilesPalLen / 4);

    draw_tilemap(game, game->camera.x, game->camera.y);

    // Enable Mode 0: 4 bgs available, but none can be rotated
    REG_DISPCNT = DCNT_MODE0 | DCNT_BG0 | DCNT_OBJ | DCNT_OBJ_1D;

    // Tiles should be at the first character block, maps should be in the last
    // Screen block
    REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_REG_64x32;

    // Initialize block OAM entries
    for (int i = 0; i < NUM_BLOCKS; i++)
    {
        obj_set_attr(&obj_buffer[i],
                     ATTR0_SQUARE | ATTR0_4BPP | 0, // y pos
                     ATTR1_SIZE_16x16 | 0, // x pos
                     ATTR2_PALBANK(0) | 5); // tile id
    }
    draw_blocks(obj_buffer, game);
}

_Noreturn void play(Game *game)
{
    Camera *camera = &game->camera;
    const Level *level = game->cur_level;

    while (1)
    {
        vid_vsync();
        REG_BG0HOFS = camera->x % 16;
        REG_BG0VOFS = camera->y % 16;
        oam_copy(oam_mem, obj_buffer, game->num_blocks);

        draw_tilemap(game, camera->x, camera->y);

        // Key presses
        key_poll();
        camera->x += key_tri_horz() * GAME_SPEED;
        if (camera->x < 0) camera->x = 0;
        if (camera->x > level->w * 16 - SCREEN_WIDTH)
            camera->x = level->w * 16 - SCREEN_WIDTH;
        camera->y += key_tri_vert() * GAME_SPEED;
        if (camera->y < 0) camera->y = 0;
        if (camera->y > level->h * 16 - SCREEN_HEIGHT)
            camera->y = level->h * 16 - SCREEN_HEIGHT;

        draw_blocks(obj_buffer, game);
    };
}