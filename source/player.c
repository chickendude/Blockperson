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
 * @param map_x The x position in the map to check
 * @param map_y The y position in the map to check
 * @param level Current level data.
 * @param blocks Array of block objects.
 * @param num_blocks Number of blocks in the level.
 *
 * @return true = Something is blocking the player, false = The tile is open
 */
bool check_collision(int map_x, int map_y, const Level *level, Block *blocks,
                     int num_blocks);

/**
 * Updates the player's sprite.
 *
 * @param player Main Player object
 */
void update_animation(Player *player);

// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void move_player(Game *game)
{
    Player *player = &game->player;
    Camera *camera = &game->camera;
    const Level *level = game->cur_level;

    // Move player
    if (player->animation_frames == 0)
    {
        check_keys(player, level, game->blocks, game->num_blocks);
    } else
    {
        update_animation(player);
    }

    obj_set_pos(player->oam, player->x - camera->x, player->y - camera->y);
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------

void
check_keys(Player *player, const Level *level, Block *blocks, int num_blocks)
{
    int map_x, map_y;

    // Convert player's coordinates into map coordinates by dividing by 16
    map_x = player->x >> 4;
    map_y = player->y >> 4;

    // Check key presses
    if (key_is_down(KEY_LEFT) &&
        !check_collision(map_x - 1, map_y, level, blocks, num_blocks))
    {
        player->dx = -GAME_SPEED;
        player->direction = -1;
        player->animation_frames = 8;
        player->oam->attr1 &= ~ATTR1_HFLIP;
    } else if (key_is_down(KEY_RIGHT) &&
               !check_collision(map_x + 1, map_y, level, blocks, num_blocks))
    {
        player->dx = GAME_SPEED;
        player->direction = 1;
        player->animation_frames = 8;
        player->oam->attr1 |= ATTR1_HFLIP;
    } else if (key_is_down(KEY_UP))
    {
        // Only jump if the tile to the left is blocked but the tile above it
        // is not blocked
        if (check_collision(map_x - 1, map_y, level, blocks, num_blocks) &&
            !check_collision(map_x - 1, map_y - 1, level, blocks, num_blocks))
        {
            player->dy = -GAME_SPEED;
            player->animation_frames = 8;
        }
    }
}

bool
check_collision(int map_x, int map_y, const Level *level, Block *blocks,
                int num_blocks)
{
    if (level->tilemap[map_y * level->w + map_x] == 'B')
    {
        return true;
    }

    for (int i = 0; i < num_blocks; i++)
    {
        if (blocks[i].x >> 4 == map_x && blocks[i].y >> 4 == map_y)
        {
            return true;
        }
    }

    return false;
}

void update_animation(Player *player)
{
    player->animation_frames--;
    player->x += player->dx;
    player->y += player->dy;

    // If animation frame reached 0 this frame, handle end of animation.
    // TODO: May want to look into setting up a FSM here
    if (player->animation_frames == 0)
    {
        // If dy is not zero, the player was jumping so we need to scoot them
        // over one tile as well.
        if (player->dy != 0)
        {
            player->dy = 0;
            player->dx = player->direction * GAME_SPEED;
            player->animation_frames = 8;
        } else
        {
            player->dx = 0;
        }
    }

    // Update player's sprite according to animation frame
    player->oam->attr2 &= ~ATTR2_ID_MASK;
    player->oam->attr2 |= 13 + (player->animation_frames >> 2) * 4;
}