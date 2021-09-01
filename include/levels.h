#ifndef BLOCKPERSON_LEVELS_H
#define BLOCKPERSON_LEVELS_H

#include "types.h"
#include "objects.h"

struct Level {
    const Map *map;
    Block blocks[50];
};

void load_level(Game *game, const Level *level);

extern const Level level_1;

#endif //BLOCKPERSON_LEVELS_H
