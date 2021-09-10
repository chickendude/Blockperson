#include "camera.h"
#include "constants.h"
#include "game.h"
#include "levels.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void update_camera(Game *game)
{
    int cam_x, right_edge, difference_x;
    const Level *level = game->cur_level;
    Camera *camera = &game->camera;
    Player *player = &game->player;

    // Handle camera's x coordinates
    cam_x = player->x - SCREEN_WIDTH / 2;
    right_edge = level->w * TILE_SIZE - SCREEN_WIDTH;

    // Limit camera so it doesn't go beyond edges
    cam_x = cam_x > right_edge ? right_edge : cam_x;
    cam_x = cam_x < 0 ? 0 : cam_x;
    difference_x = camera->x - cam_x;
    if (difference_x < 0)
    {
        camera->x += (-difference_x >> 3) + 1;
    } else if (difference_x > 0)
    {
        camera->x -= (difference_x >> 3) + 1;
    }
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------