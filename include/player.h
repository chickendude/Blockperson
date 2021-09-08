#ifndef BLOCKPERSON_PLAYER_H
#define BLOCKPERSON_PLAYER_H

#include <tonc.h>
#include "types.h"

typedef enum State {
    WALKING,
    LIFTING_BLOCK,
    HOLDING_BLOCK,
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
