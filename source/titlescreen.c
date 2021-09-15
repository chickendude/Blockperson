#include "titlescreen.h"
#include "game.h"
#include "levels.h"
// Tile data
#include "pause_screen.h"
#include "title_screen.h"

int MOVES[] = {
        KEY_L, KEY_A, KEY_L, -1
};
// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void show_titlescreen(Game *game, OBJ_ATTR *obj_buffer)
{
    Player *player = &game->player;
    Camera *camera = &game->camera;

    memcpy32(&tile_mem[1][1], title_screenTiles, title_screenTilesLen / 4);
    REG_DISPCNT |= DCNT_BG2;

    load_next_level(game);
    draw_tilemap(game);
    draw_blocks(obj_buffer, game);

    while (!key_released(KEY_START))
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

        // Update camera
        update_camera(game);

        draw_blocks(obj_buffer, game);
        move_player(game, MOVES);
        obj_set_pos(player->oam, player->x - camera->x,
                    player->y - camera->y);
    }

    game->level_id = 0;

    REG_DISPCNT &= ~DCNT_BG2;
    memcpy32(&tile_mem[1][1], pause_screenTiles, pause_screenTilesLen / 4);
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------