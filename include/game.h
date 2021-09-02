#ifndef BLOCKPERSON_GAME_H
#define BLOCKPERSON_GAME_H

#include "types.h"
#include "camera.h"
#include "objects.h"

struct Game {
    Camera camera;
    const Level *cur_level;
    int num_blocks;
    Block blocks[50];
};

#endif //BLOCKPERSON_GAME_H
