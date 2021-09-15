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

void load_next_level(Game *game, OBJ_ATTR *obj_buffer);

extern const Level *levels[11];

extern const Level level_1, level_2, level_3, level_4, level_5, level_6,
        level_7, level_8, level_9, level_10, level_11;

#endif //BLOCKPERSON_LEVELS_H
