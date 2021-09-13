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
    int cam_x, cam_y, edge, difference;
    const Level *level = game->cur_level;
    Camera *camera = &game->camera;
    Player *player = &game->player;

    // Handle camera's x coordinates
    cam_x = player->x - SCREEN_WIDTH / 2;
    edge = level->w * TILE_SIZE - SCREEN_WIDTH;

    // Limit camera so it doesn't go beyond edges
    cam_x = cam_x > edge ? edge : cam_x;
    cam_x = cam_x < 0 ? 0 : cam_x;
    difference = camera->x - cam_x;
    if (difference < 0)
    {
        camera->x += (-difference >> 3) + 1;
    } else if (difference > 0)
    {
        camera->x -= (difference >> 3) + 1;
    }

    // Handle camera's y coordinates
    cam_y = player->y - SCREEN_HEIGHT / 2;
    edge = level->h * TILE_SIZE - SCREEN_HEIGHT;

    // Limit camera so it doesn't go beyond edges
    cam_y = cam_y > edge ? edge : cam_y;
    cam_y = cam_y < 0 ? 0 : cam_y;
    difference = camera->y - cam_y;
    if (difference < 0)
    {
        camera->y += (-difference >> 3) + 1;
    } else if (difference > 0)
    {
        camera->y -= (difference >> 3) + 1;
    }
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------