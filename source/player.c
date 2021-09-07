#include <tonc.h>
#include "player.h"
#include "constants.h"
#include "game.h"
#include "levels.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------

/**
 * Checks the keypad to handle player actions such as walking, climbing,
 * picking up blocks, etc.
 *
 * @param player Main Player object.
 * @param level Current level data.
 * @param blocks Array of block objects.
 * @param num_blocks Number of blocks in the level.
 */
void
check_keys(Player *player, const Level *level, Block *blocks, int num_blocks);

/**
 * Checks if the tile in the direction the player is facing is walkable.
 *
 * If it is a block or wall, the player's `dx` and `animation_frame` value will
 * be reset to 0.
 *
 * @param player Main Player object.
 * @param level Current level data.
 * @param blocks Array of block objects.
 * @param num_blocks Number of blocks in the level.
 */
void check_collision(Player *player, const Level *level, Block *blocks,
                     int num_blocks);

// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void move_player(Game *game)
{
    Player *player = &game->player;
    Camera *camera = &game->camera;
    const Level *level = game->cur_level;

    check_keys(player, level, game->blocks, game->num_blocks);
    check_collision(player, level, game->blocks, game->num_blocks);

    // Move player
    if (player->animation_frames > 0)
    {
        player->animation_frames--;
        player->x += player->dx;

        if (player->animation_frames == 0) player->dx = 0;

        // Update player's sprite according to animation frame
        player->oam->attr2 &= ~ATTR2_ID_MASK;
        player->oam->attr2 |= 13 + (player->animation_frames >> 2) * 4;
    }

    obj_set_pos(player->oam, player->x - camera->x, player->y - camera->y);
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------

void
check_keys(Player *player, const Level *level, Block *blocks, int num_blocks)
{
    // Only allow new direction to be chosen after the previous animation has
    // finished.
    if (player->animation_frames != 0) return;

    // Check key presses
    if (key_is_down(KEY_LEFT))
    {
        player->dx = -GAME_SPEED;
        player->animation_frames = 8;
        player->oam->attr1 &= ~ATTR1_HFLIP;
    } else if (key_is_down(KEY_RIGHT))
    {
        player->dx = GAME_SPEED;
        player->animation_frames = 8;
        player->oam->attr1 |= ATTR1_HFLIP;
    }
}

void
check_collision(Player *player, const Level *level, Block *blocks,
                int num_blocks)
{
    // Player's position converted to map coordinates
    int map_x, map_y;

    // Can exit if dx is 0 as player is not moving or in the middle of moving.
    if (player->dx == 0 || (player->x & 0xf) != 0) return;

    map_x = player->x / TILE_SIZE;
    map_y = player->y / TILE_SIZE;

    // Adjust map position according to direction player is facing
    map_x += player->dx > 0 ? 1 : -1;

    if (level->tilemap[map_y * level->w + map_x] == 'B')
    {
        player->dx = 0;
        player->animation_frames = 0;
        return;
    }

    for (int i = 0; i < num_blocks; i++)
    {
        if (blocks[i].x >> 4 == map_x && blocks[i].y >> 4 == map_y)
        {
            player->dx = 0;
            player->animation_frames = 0;
            break;
        }
    }
}