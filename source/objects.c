#include "objects.h"
#include "constants.h"
#include "game.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------
void draw_blocks(OBJ_ATTR *obj_buffer, Game *game)
{
    int p_x, p_y, num_blocks;
    Block *blocks, *b;
    Camera *cam;

    num_blocks = game->num_blocks;
    blocks = game->blocks;
    cam = &game->camera;
    p_x = game->player.x;
    p_y = game->player.y;

    for (int i = 0; i < num_blocks; i++)
    {
        b = &blocks[i];

        // Check if block is on the ground or not
        if (!b->on_ground) {
            if (b->y > p_y - TILE_SIZE) {
                b->y-= GAME_SPEED;
            } else if (b->y < p_y - TILE_SIZE) {
                b->y+= GAME_SPEED;
            } else if (b->x > p_x) {
                b->x-= GAME_SPEED;
            } else if (b->x < p_x) {
                b->x+= GAME_SPEED;
            }
        }

        // First object in oam should be the player, hence we add 1.
        obj_set_pos(&obj_buffer[i + 1],
                    blocks[i].x - cam->x,
                    blocks[i].y - cam->y);
    }
}

Block* get_block(int map_x, int map_y, Block *blocks, int num_blocks)
{
    for (int i = 0; i < num_blocks; i++)
    {
        if (blocks[i].x >> 4 == map_x &&
            blocks[i].y >> 4 == map_y)
        {
            return &blocks[i];
        }
    }

    return NULL;
}
// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------