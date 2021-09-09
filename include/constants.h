#ifndef BLOCKPERSON_CONSTANTS_H
#define BLOCKPERSON_CONSTANTS_H

/** Number of 16x16 columns in a screen block */
#define SB_COLS (32 / (TILE_SIZE / 8))

/** Pixels per frame to move. */
#define GAME_SPEED 2

/** Maximum number of blocks in a level. */
#define NUM_BLOCKS 50

/** Maximum number of sprites that can be drawn on screen. */
#define NUM_SPRITES (NUM_BLOCKS + 1)

/** Number of tiles that fit in one row in a screen block. */
#define NUM_TILES_IN_ROW 32

/** Number of 16x16 rows in a screen block */
#define SB_ROWS (32 / (TILE_SIZE / 8))

#define TILE_SIZE 16

#define TILE(n) (1 + (n * 4))
#endif //BLOCKPERSON_CONSTANTS_H
