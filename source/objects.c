#include "objects.h"
#include "game.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------
void draw_blocks(OBJ_ATTR *obj_buffer, Game *game)
{
    int num_blocks = game->num_blocks;
    Block *blocks = game->blocks;
    Camera *cam = &game->camera;
    for (int i = 0; i < num_blocks; i++)
    {
        // First object in oam should be the player, hence we add 1.
        obj_set_pos(&obj_buffer[i + 1],
                    blocks[i].x - cam->x,
                    blocks[i].y - cam->y);
    }
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------