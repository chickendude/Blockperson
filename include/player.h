#ifndef BLOCKPERSON_PLAYER_H
#define BLOCKPERSON_PLAYER_H

#include <tonc.h>
#include "types.h"

typedef enum State {
    IDLE,
    WALKING,
    JUMPING,
    FALLING,
    LIFTING_BLOCK,
    HOLDING_BLOCK_IDLE,
    HOLDING_BLOCK_WALKING,
    HOLDING_BLOCK_JUMPING,
    HOLDING_BLOCK_FALLING,
    RELEASING_BLOCK
} State;

struct Player {
    int x, y;
    int dx, dy;
    int animation_frames;
    /** Left == -1, Right == 1 */
    int direction;
    State state;
    Block *lifted_block;
    OBJ_ATTR *oam;
};

void move_player(Game *game);

#endif //BLOCKPERSON_PLAYER_H
