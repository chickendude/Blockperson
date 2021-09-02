#ifndef BLOCKPERSON_LEVELS_H
#define BLOCKPERSON_LEVELS_H

#include "types.h"
#include "objects.h"

struct Level
{
    int w, h;
    int start_x, start_y;
    char *tilemap;
};

void load_level(Game *game, const Level *level);

extern const Level level_1;

#endif //BLOCKPERSON_LEVELS_H
