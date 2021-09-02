#ifndef BLOCKPERSON_OBJECTS_H
#define BLOCKPERSON_OBJECTS_H

#include <tonc.h>
#include "types.h"

struct Block {
    int x, y;
    bool on_ground;
};

void draw_blocks(OBJ_ATTR *obj_buffer, Game *game);

#endif //BLOCKPERSON_OBJECTS_H
