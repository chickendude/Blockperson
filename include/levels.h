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

void load_next_level(Game *game);

extern const Level *levels[5];

extern const Level level_1, level_2, level_3, level_4, level_5;

#endif //BLOCKPERSON_LEVELS_H
