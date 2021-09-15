#include <tonc.h>
#include "constants.h"
#include "game.h"
#include "levels.h"
#include "titlescreen.h"
// Sprite data
#include "background.h"
#include "block.h"
#include "blockperson.h"
#include "tiles.h"
// Bitmap data
#include "pause_screen.h"

// TODO: Add pause/restart screen

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

void pause(Game *game);

//------------------------------------------------------------------------------
// Program entry point
//------------------------------------------------------------------------------

int main(void)
{
    Game game;
    initialize(&game);
    show_titlescreen(&game, obj_buffer);
    play(&game);
    return 0;
}

void initialize(Game *game)
{
    // Copy tile and palette data
    memcpy32(&tile_mem[0][4], tilesTiles, tilesTilesLen / 4);
    memcpy32(&tile_mem[0][12], backgroundTiles, backgroundTilesLen / 4);
    // Pause screen tiles are loaded after titlescreen is shown because they
    // share the same tilemap data
//    memcpy32(&tile_mem[1][1], pause_screenTiles, pause_screenTilesLen / 4);
    memcpy32(pal_bg_mem, tilesPal, tilesPalLen / 4);
    memcpy32(&tile_mem[4][1], blockTiles, blockTilesLen / 4);
    memcpy32(&tile_mem[4][13], blockpersonTiles, blockpersonTilesLen / 4);
    memcpy32(pal_obj_mem, blockPal, blockPalLen / 4);

    obj_set_attr(&obj_buffer[0],
                 ATTR0_SQUARE | ATTR0_4BPP | 0,
                 ATTR1_SIZE_16x16 | 0,
                 ATTR2_PRIO(1) | ATTR2_PALBANK(0) | 13);
    game->player.oam = &obj_buffer[0];
    game->player.direction = -1;

    // Initialize block OAM entries
    for (int i = 0; i < NUM_BLOCKS; i++)
    {
        game->blocks[i].is_falling = false;
        obj_set_attr(&obj_buffer[i + 1],
                     ATTR0_SQUARE | ATTR0_4BPP | 0, // y pos
                     ATTR1_SIZE_16x16 | 0, // x pos
                     ATTR2_PRIO(1) | ATTR2_PALBANK(0) | 5); // tile id
    }

    // Enable Mode 0: 4 bgs available, but none can be rotated
    REG_DISPCNT = DCNT_MODE0 | DCNT_BG0 | DCNT_BG1 | DCNT_OBJ | DCNT_OBJ_1D;

    // Tiles should be at the first character block, maps should be in the last
    // Screen block
    REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_REG_32x32 | BG_PRIO(1);
    REG_BG0HOFS = game->camera.x;
    REG_BG0VOFS = game->camera.y;

    REG_BG1CNT = BG_CBB(0) | BG_SBB(28) | BG_REG_64x32 | BG_PRIO(2);
    draw_bg_tilemap();

    REG_BG2CNT = BG_CBB(1) | BG_SBB(27) | BG_REG_32x32 | BG_PRIO(0);
    // Load tilemap data used for the title and pause screens
    int tile_id = 1;
    for (int j = 5; j < 13; j++)
    {
        for (int i = 5; i < 25; i++)
        {
            se_mem[27][j * 32 + i] = tile_id++;
        }
    }
}

void play(Game *game)
{
    Camera *camera;
    Player *player;

    while (game->level_id < NUM_LEVELS)
    {
        load_next_level(game, obj_buffer);

        camera = &game->camera;
        player = &game->player;

        // Check for KEY_SELECT
        // Without this, the keys never get updated after pressing [select]
        key_poll();

        while (!reached_door(game) && !key_released(KEY_SELECT))
        {
            vid_vsync();
            // Foreground
            REG_BG0HOFS = camera->x;
            REG_BG0VOFS = camera->y;

            // Background (parallax scrolling)
            REG_BG1HOFS = camera->x >> 3;
            REG_BG1VOFS = camera->y >> 3;

            // Copy buffer data to oam_mem, only sprites are the blocks and the
            // player, hence the +1 (for the player's sprite).
            oam_copy(oam_mem, obj_buffer, game->num_blocks + 1);

            update_tilemap(game);

            // Key presses
            key_poll();

            if (key_is_down(KEY_START)) pause(game);

            // Update camera
            update_camera(game);

            draw_blocks(obj_buffer, game);
            move_player(game);
            obj_set_pos(player->oam, player->x - camera->x,
                        player->y - camera->y);
        }
    }
}

void pause(Game *game)
{
    REG_DISPCNT |= DCNT_BG2;

    bool is_paused = true;
    while (is_paused)
    {
        vid_vsync();
        key_poll();
        is_paused = !key_is_down(KEY_B);
        if (key_is_down(KEY_R) && key_is_down(KEY_L))
        {
            game->level_id--;
            load_next_level(game, obj_buffer);
            is_paused = false;
        }
    }

    REG_DISPCNT &= ~DCNT_BG2;
}
