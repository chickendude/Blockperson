#ifndef BLOCKPERSON_GAME_H
#define BLOCKPERSON_GAME_H

#include "types.h"
#include "camera.h"

struct Game {
    Camera camera;
    const Level *cur_level;
};

#endif //BLOCKPERSON_GAME_H
