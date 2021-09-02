#ifndef BLOCKPERSON_CONSTANTS_H
#define BLOCKPERSON_CONSTANTS_H


#define COLUMNS (SCREEN_WIDTH / TILE_SIZE)

/** Pixels per frame to move. */
#define GAME_SPEED 2

/** Maximum number of blocks in a level. */
#define NUM_BLOCKS 50

/** Maximum number of sprites that can be drawn on screen. */
#define NUM_SPRITES (NUM_BLOCKS + 1)

/** Number of tiles that fit in one row in a screen block. */
#define NUM_TILES_IN_ROW 32

#define TILE_SIZE 16
#define ROWS (SCREEN_HEIGHT / TILE_SIZE)

#endif //BLOCKPERSON_CONSTANTS_H
