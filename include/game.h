#ifndef BLOCKPERSON_GAME_H
#define BLOCKPERSON_GAME_H

#include "types.h"
#include "camera.h"
#include "objects.h"
#include "player.h"

struct Game {
    Camera camera;
    Camera prev_camera;
    Player player;
    int level_id;
    const Level *cur_level;
    int num_blocks;
    Block blocks[50];
};

/**
 * Draws the entire map to the screen based on the current camera coordinates.
 */
void draw_tilemap(Game *game);

/**
 * Extracts blocks and player position from the tilemap.
 *
 * Since we only parse part of the tilemap when drawing it for the first time
 * in `draw_tilemap`, we need to do a full pass of the tilemap to extract the
 * blocks and the player's position.
 */
void extract_tilemap(Game *game);

/**
 * Only updates the parts of the map that are going off screen.
 *
 * @param game The main game object
 */
void update_tilemap(Game *game);

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
bool is_blocked(int map_x, int map_y, const Level *level, Block *blocks,
                int num_blocks);

/**
 * Checks if player has reached a door tile.
 *
 * @param game Main Game object.
 * @return true = yes, false = no
 */
bool reached_door(Game *game);

#endif //BLOCKPERSON_GAME_H
