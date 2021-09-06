#include <tonc.h>
#include "player.h"
#include "constants.h"
#include "game.h"
#include "levels.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void move_player(Game *game)
{
    int map_x, map_y;
    Player *player = &game->player;
    Camera *camera = &game->camera;
    const Level *level = game->cur_level;

    if (player->animation_frames == 0)
    {
        map_x = player->x / TILE_SIZE;
        map_y = player->y / TILE_SIZE;
        if (key_is_down(KEY_LEFT))
        {
            if (level->tilemap[map_y * level->w + map_x - 1] != 'B')
            {
                player->dx = -GAME_SPEED;
                player->animation_frames = 8;
            }
        } else if (key_is_down(KEY_RIGHT))
        {
            if (level->tilemap[map_y * level->w + map_x + 1] != 'B')
            {
                player->dx = GAME_SPEED;
                player->animation_frames = 8;
            }
        }
    }

    // Move player
    if (player->animation_frames > 0)
    {
        player->animation_frames--;
        player->x += player->dx;
    }

    obj_set_pos(player->oam, player->x - camera->x, player->y - camera->y);
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------