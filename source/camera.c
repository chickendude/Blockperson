#include "camera.h"
#include "constants.h"
#include "game.h"
#include "levels.h"

/** Set the max value for an expression. */
#define LIMIT(expr, max) (expr) > max ? max : (expr)

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------
/**
 * The camera should center around the player.
 */
void follow_player(Game *game);

/**
 * The camera is controlled directly by the player.
 */
void free_roam(Game *game);

/**
 * Makes sure camera doesn't go beyond the x bounds of the level.
 */
int limit_cam_x(int cam_x, int level_w);

/**
 * Makes sure camera doesn't go beyond the y bounds of the level.
 */
int limit_cam_y(int cam_x, int level_h);

// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void update_camera(Game *game)
{
    if (key_is_down(KEY_B)) free_roam(game);
    else follow_player(game);
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------
void follow_player(Game *game)
{

    int cam_x, cam_y, difference;
    const Level *level = game->cur_level;
    Camera *camera = &game->camera;
    Player *player = &game->player;

    // Handle camera's x coordinates
    cam_x = limit_cam_x(player->x - SCREEN_WIDTH / 2, level->w);

    difference = camera->x - cam_x;
    if (difference < 0)
    {
        camera->x += LIMIT((-difference >> 3) + 1, 6);
    } else if (difference > 0)
    {
        camera->x -= LIMIT((difference >> 3) + 1, 6);
    }

    // Handle camera's y coordinates
    cam_y = limit_cam_y(player->y - SCREEN_HEIGHT / 2, level->h);

    difference = camera->y - cam_y;
    if (difference < 0)
    {
        camera->y += LIMIT((-difference >> 3) + 1, 5);
    } else if (difference > 0)
    {
        camera->y -= LIMIT((difference >> 3) + 1, 5);
    }
}

void free_roam(Game *game)
{
    Camera *camera = &game->camera;
    const Level *level = game->cur_level;
    camera->x = limit_cam_x(camera->x + key_tri_horz() * GAME_SPEED, level->w);
    camera->y = limit_cam_y(camera->y + key_tri_vert() * GAME_SPEED, level->h);
}

int limit_cam_x(int cam_x, int level_w)
{
    int edge;

    // Limit camera so it doesn't go beyond edges
    edge = level_w * TILE_SIZE - SCREEN_WIDTH;

    cam_x = cam_x > edge ? edge : cam_x;
    cam_x = cam_x < 0 ? 0 : cam_x;

    return cam_x;
}

int limit_cam_y(int cam_y, int level_h)
{
    int edge;

    edge = level_h * TILE_SIZE - SCREEN_HEIGHT;

    // Limit camera so it doesn't go beyond edges
    cam_y = cam_y > edge ? edge : cam_y;
    cam_y = cam_y < 0 ? 0 : cam_y;

    return cam_y;
}