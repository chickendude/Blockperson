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
    for (int i = 1; i <= num_blocks; i++)
    {
        obj_set_pos(&obj_buffer[i],
                    blocks[i].x - cam->x,
                    blocks[i].y - cam->y);
    }
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------