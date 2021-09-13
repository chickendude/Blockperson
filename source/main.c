#include <tonc.h>
#include "constants.h"
#include "game.h"
#include "levels.h"
// Sprite data
#include "block.h"
#include "blockperson.h"
#include "tiles.h"

// TODO: Add second background for parallax scrolling
// TODO: Add vertical scrolling to camera
// TODO: Hold button to scroll map without moving player

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
void play(Game *game);

//------------------------------------------------------------------------------
// Program entry point
//------------------------------------------------------------------------------

int main(void)
{
    Game game;
    initialize(&game);
    play(&game);
    return 0;
}

void initialize(Game *game)
{
    // Copy tile and palette data
    memcpy32(&tile_mem[0][4], tilesTiles, tilesTilesLen / 4);
    memcpy32(pal_bg_mem, tilesPal, tilesPalLen / 4);
    memcpy32(&tile_mem[4][1], blockTiles, blockTilesLen / 4);
    memcpy32(&tile_mem[4][13], blockpersonTiles, blockpersonTilesLen / 4);
    memcpy32(pal_obj_mem, blockPal, blockPalLen / 4);

    obj_set_attr(&obj_buffer[0],
                 ATTR0_SQUARE | ATTR0_4BPP | 0,
                 ATTR1_SIZE_16x16 | 0,
                 ATTR2_PALBANK(0) | 13);
    game->player.oam = &obj_buffer[0];
    game->player.direction = -1;

    // Initialize block OAM entries
    for (int i = 0; i < NUM_BLOCKS; i++)
    {
        game->blocks[i].is_falling = false;
        obj_set_attr(&obj_buffer[i + 1],
                     ATTR0_SQUARE | ATTR0_4BPP | 0, // y pos
                     ATTR1_SIZE_16x16 | 0, // x pos
                     ATTR2_PALBANK(0) | 5); // tile id
    }

    // Enable Mode 0: 4 bgs available, but none can be rotated
    REG_DISPCNT = DCNT_MODE0 | DCNT_BG0 | DCNT_OBJ | DCNT_OBJ_1D;

    // Tiles should be at the first character block, maps should be in the last
    // Screen block
    REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_REG_32x32;
    REG_BG0HOFS = game->camera.x;
    REG_BG0VOFS = game->camera.y;
}

void play(Game *game)
{
    Camera *camera;

    while (game->level_id < NUM_LEVELS)
    {
        load_next_level(game);
        draw_tilemap(game);
        draw_blocks(obj_buffer, game);

        camera = &game->camera;

        while (!reached_door(game))
        {
            vid_vsync();
            REG_BG0HOFS = camera->x;
            REG_BG0VOFS = camera->y;

            // Copy buffer data to oam_mem, only sprites are the blocks and the
            // player, hence the +1 (for the player's sprite).
            oam_copy(oam_mem, obj_buffer, game->num_blocks + 1);

            update_tilemap(game);

            // Key presses
            key_poll();

            // Update camera
            update_camera(game);

            draw_blocks(obj_buffer, game);
            move_player(game);
        }
    }
}