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
    int num_blocks, map_x, map_y;
    Block *blocks;
    Block *b;
    Camera *cam;

    num_blocks = game->num_blocks;
    blocks = game->blocks;
    cam = &game->camera;

    for (int i = 0; i < num_blocks; i++)
    {
        b = &blocks[i];
        if (b->is_falling)
        {
            map_x = b->x / TILE_SIZE;
            map_y = b->y / TILE_SIZE;
            if ((b->y & 0xf) == 0)
            {
                if (is_blocked(map_x, map_y + 1, game->cur_level, blocks,
                               num_blocks))
                {
                    b->is_falling = false;
                }
            }
            if (b->is_falling) b->y += GAME_SPEED;
        }
        // First object in oam should be the player, hence we add 1.
        obj_set_pos(&obj_buffer[i + 1],
                    b->x - cam->x,
                    b->y - cam->y);
    }
}

Block *get_block(int map_x, int map_y, Block *blocks, int num_blocks)
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