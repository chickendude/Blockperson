#ifndef BLOCKPERSON_GAME_H
#define BLOCKPERSON_GAME_H

#include "types.h"
#include "camera.h"
#include "objects.h"

struct Game {
    Camera camera;
    Camera prev_camera;
    const Level *cur_level;
    int num_blocks;
    Block blocks[50];
};

/**
 * Draws the entire map to the screen based on the current camera coordinates.
 */
void draw_tilemap(Game *game);

/**
 * Only updates the parts of the map that are going off screen.
 *
 * @param game The main game object containing
 */
void update_tilemap(Game *game);

#endif //BLOCKPERSON_GAME_H
