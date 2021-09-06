#include <tonc.h>
#include "player.h"
#include "constants.h"
#include "game.h"
#include "levels.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------

void check_keys(Player *player, const Level *level);

// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void move_player(Game *game)
{
    Player *player = &game->player;
    Camera *camera = &game->camera;
    const Level *level = game->cur_level;

    check_keys(player, level);

    // Move player
    if (player->animation_frames > 0)
    {
        player->animation_frames--;
        player->x += player->dx;
        player->oam->attr2 &= ~ATTR2_ID_MASK;
        player->oam->attr2 |= 13 + (player->animation_frames >> 2) * 4;
    }

    obj_set_pos(player->oam, player->x - camera->x, player->y - camera->y);
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------

void check_keys(Player *player, const Level *level) {
    int map_x, map_y;

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
            player->oam->attr1 &= ~ATTR1_HFLIP;
        } else if (key_is_down(KEY_RIGHT))
        {
            if (level->tilemap[map_y * level->w + map_x + 1] != 'B')
            {
                player->dx = GAME_SPEED;
                player->animation_frames = 8;
            }
            player->oam->attr1 |= ATTR1_HFLIP;
        }
    }
}