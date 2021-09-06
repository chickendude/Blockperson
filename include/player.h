#ifndef BLOCKPERSON_PLAYER_H
#define BLOCKPERSON_PLAYER_H

#include <tonc.h>
#include "types.h"

struct Player {
    int x, y;
    int dx, dy;
    int animation_frames;
    OBJ_ATTR *oam;
};

void move_player(Game *game);

#endif //BLOCKPERSON_PLAYER_H