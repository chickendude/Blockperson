#include <tonc.h>
#include "player.h"
#include "constants.h"
#include "game.h"
#include "levels.h"

/*
 * Player States:
 * - Idle
 * - Walking
 * - Lifting block
 * - Holding block
 * - Releasing block
 * - Falling
 */

#define TILE(n) (1 + (n * 4))

static int *AUTO;

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
 * Checks if the tile beneath the player is empty or not.
 *
 * Basically checks if the player should fall or not.
 *
 * @param player Main Player object.
 * @param level Current level data.
 * @param blocks Array of block objects.
 * @param num_blocks Number of blocks in the level.
 */
void check_falling(Player *player, const Level *level, Block *blocks,
                   int num_blocks);

/**
 * Updates the player's sprite.
 *
 * @param player Main Player object
 */
void update_walking(Player *player);

void update_lifting_block(Player *player);

void update_dropping_block(Player *player);

void update_jumping(Player *player);

void update_falling(Player *player);

void update_holding_block_walking(Player *player);

void update_holding_block_idle(Player *player);

void update_holding_block_jumping(Player *player);

void update_holding_block_falling(Player *player);

// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void load_moves(int *moves)
{
    // Load the list of moves (if there are any)
    AUTO = moves;
}

void move_player(Game *game)
{
    Player *player = &game->player;
    const Level *level = game->cur_level;

    // If B is pressed, don't move the player as we're going to be controlling
    // the camera instead
    if (key_is_down(KEY_B)) return;

    // Move player
    if (player->state == IDLE || player->state == HOLDING_BLOCK_IDLE)
    {
        check_keys(player, level, game->blocks, game->num_blocks);
        check_falling(player, level, game->blocks, game->num_blocks);
    }

    // Animate and move sprite
    switch (player->state)
    {
        case IDLE:
            player->oam->attr2 &= ~ATTR2_ID_MASK;
            player->oam->attr2 |= TILE(3);
            break;
        case WALKING:
            update_walking(player);
            break;
        case LIFTING_BLOCK:
            update_lifting_block(player);
            break;
        case DROPPING_BLOCK:
            update_dropping_block(player);
            break;
        case JUMPING:
            update_jumping(player);
            break;
        case FALLING:
            update_falling(player);
            break;
        case HOLDING_BLOCK_WALKING:
            update_holding_block_walking(player);
            break;
        case HOLDING_BLOCK_IDLE:
            update_holding_block_idle(player);
            break;
        case HOLDING_BLOCK_JUMPING:
            update_holding_block_jumping(player);
            break;
        case HOLDING_BLOCK_FALLING:
            update_holding_block_falling(player);
            break;
        case RELEASING_BLOCK:
            break;
    }

}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------

void
check_keys(Player *player, const Level *level, Block *blocks, int num_blocks)
{
    int map_x, map_y;
    bool moved = false;

    // Handle auto actions
    int auto_action = AUTO != NULL ? AUTO++[0] : 0;
    // Quit if it's the last action
    if (auto_action < 0)
    {
        AUTO = NULL;
        return;
    }

    // Convert player's coordinates into map coordinates by dividing by 16
    map_x = player->x >> 4;
    map_y = player->y >> 4;

    player->animation_frames = 0;

    // Check key presses
    if (auto_action == KEY_LEFT || (!auto_action && key_is_down(KEY_LEFT)))
    {
        player->direction = -1;
        player->oam->attr1 &= ~ATTR1_HFLIP;
        moved = true;
    } else if (auto_action == KEY_RIGHT ||
               (!auto_action && key_is_down(KEY_RIGHT)))
    {
        player->direction = 1;
        player->oam->attr1 |= ATTR1_HFLIP;
        moved = true;
    }

    if (moved && !is_blocked(map_x + player->direction, map_y, level, blocks,
                             num_blocks))
    {
        // If player is holding a block, we also need to check the tile
        // above them
        if (player->state != HOLDING_BLOCK_IDLE ||
            !is_blocked(map_x + player->direction, map_y - 1, level, blocks,
                        num_blocks))
        {
            player->state =
                    player->state == IDLE ? WALKING : HOLDING_BLOCK_WALKING;
        }
    }

    if (auto_action == KEY_UP || (!auto_action && key_is_down(KEY_UP)))
    {
        // Only jump if the tile to the left is blocked but the tile above it
        // is not blocked
        if (is_blocked(map_x + player->direction, map_y, level, blocks,
                       num_blocks) &&
            !is_blocked(map_x + player->direction, map_y - 1, level, blocks,
                        num_blocks))
        {
            // Make sure:
            // 1. If not holding block, tile above player is free.
            // 2. If holding block, tiles above the block and to the right are
            //    free.
            if ((player->state != HOLDING_BLOCK_IDLE &&
                 !is_blocked(
                         map_x,
                         map_y - 1,
                         level, blocks, num_blocks)) ||
                 (player->state == HOLDING_BLOCK_IDLE &&
                         !is_blocked(
                         map_x,
                         map_y - 2,
                         level, blocks, num_blocks) &&
                  !is_blocked(
                          map_x + player->direction,
                          map_y - 2,
                          level, blocks, num_blocks)))
            {
                player->state =
                        player->state == IDLE ? JUMPING : HOLDING_BLOCK_JUMPING;
            }
        }
    } else if (player->lifted_block == NULL &&
               (auto_action == KEY_A ||
                (!auto_action && key_is_down(KEY_A))))
    {
        map_x += player->direction;
        // If the tile in front of the player is a block with nothing above it
        if (get_block(map_x, map_y, blocks, num_blocks) &&
            !is_blocked(map_x, map_y - 1, level, blocks, num_blocks) &&
            !is_blocked(map_x - player->direction, map_y - 1, level, blocks,
                        num_blocks))
        {
            player->lifted_block = get_block(map_x, map_y, blocks, num_blocks);
            player->state = LIFTING_BLOCK;
        }
    } else if (player->lifted_block != NULL &&
               (auto_action == KEY_A ||
                (!auto_action && key_is_down(KEY_A))))
    {
        map_x += player->direction;
        // If there is nothing blocking the player from dropping the block,
        // switch to dropping state.
        if (!is_blocked(map_x, map_y - 1, level, blocks, num_blocks))
        {
            player->state = DROPPING_BLOCK;
        }
    }
}

void check_falling(Player *player, const Level *level, Block *blocks,
                   int num_blocks)
{
    int map_x, map_y;
    map_x = player->x >> 4;
    map_y = player->y >> 4;
    if (!is_blocked(map_x, map_y + 1, level, blocks, num_blocks))
    {
        player->animation_frames = 0;
        player->state = (player->state == IDLE || player->state == WALKING)
                        ? FALLING : HOLDING_BLOCK_FALLING;
    }
}

// Walking

void update_walking_base(Player *player, int base_tile, State next_state)
{
    player->animation_frames++;

    player->x += player->direction * GAME_SPEED;

    if (player->animation_frames == 8)
    {
        player->state = next_state;
    } else if (player->animation_frames >= 4)
    {
        base_tile += 4;
    }

    // Update player's sprite according to animation frame
    player->oam->attr2 &= ~ATTR2_ID_MASK;
    player->oam->attr2 |= base_tile;
}

void update_walking(Player *player)
{
    update_walking_base(player, TILE(3), IDLE);
}

void update_holding_block_walking(Player *player)
{
    update_walking_base(player, TILE(11), HOLDING_BLOCK_IDLE);
    player->lifted_block->x = player->x;
    player->lifted_block->y = player->y - TILE_SIZE;
}

// Lifting block

void update_lifting_block(Player *player)
{
    Block *b = player->lifted_block;

    if (b->y != player->y - TILE_SIZE)
    {
        b->y -= GAME_SPEED;
    } else if (b->x != player->x)
    {
        b->x -= player->direction * GAME_SPEED;
    } else
    {
        player->state = HOLDING_BLOCK_IDLE;
    }

    // Update player's sprite according to animation frame
    player->animation_frames++;
    player->oam->attr2 &= ~ATTR2_ID_MASK;
    player->oam->attr2 |= TILE(4) + (player->animation_frames >> 2) * 4;
}

// Dropping block

void update_dropping_block(Player *player)
{
    Block *b = player->lifted_block;

    if (b != NULL && b->x != player->x + player->direction * TILE_SIZE)
    {
        b->x += player->direction * GAME_SPEED;
    } else if (player->animation_frames == 8)
    {
        b->is_falling = true;
        player->lifted_block = NULL;
    } else if (player->animation_frames == 16)
    {
        player->state = IDLE;
    }

    // Update player's sprite according to animation frame
    player->animation_frames++;
    player->oam->attr2 &= ~ATTR2_ID_MASK;
    player->oam->attr2 |= TILE(8) - (player->animation_frames >> 2) * 4;
}

// Idle

void update_holding_block_idle(Player *player)
{
    int frame, t_id;

    // Increase animation frame and strip upper bits out
    frame = ++player->animation_frames & 0x3F;

    // If the frame is between 0x2A and 0x3F, use tile 12.
    t_id = frame > 0x2A ? TILE(12) : TILE(11);
    player->oam->attr2 &= ~ATTR2_ID_MASK;
    player->oam->attr2 |= t_id;
}

// Jumping

void update_jumping_base(Player *player, State next_state)
{
    player->animation_frames++;

    if (player->animation_frames <= 8)
    {
        player->y -= GAME_SPEED;
    } else if (player->animation_frames <= 16)
    {
        player->x += player->direction * GAME_SPEED;
    } else
    {
        player->state = next_state;
    }
}

void update_jumping(Player *player)
{
    update_jumping_base(player, IDLE);
}

void update_holding_block_jumping(Player *player)
{
    update_jumping_base(player, HOLDING_BLOCK_IDLE);
    player->lifted_block->x = player->x;
    player->lifted_block->y = player->y - TILE_SIZE;
}

// Falling

void update_falling_base(Player *player, State next_state)
{
    player->animation_frames++;

    if (player->animation_frames == 8)
        player->state = next_state;

    player->y += GAME_SPEED;

}

void update_falling(Player *player)
{
    update_falling_base(player, IDLE);
}

void update_holding_block_falling(Player *player)
{
    update_falling_base(player, HOLDING_BLOCK_IDLE);
    player->lifted_block->x = player->x;
    player->lifted_block->y = player->y - TILE_SIZE;
}