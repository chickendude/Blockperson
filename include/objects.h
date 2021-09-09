#ifndef BLOCKPERSON_OBJECTS_H
#define BLOCKPERSON_OBJECTS_H

#include <tonc.h>
#include "types.h"

struct Block {
    int x, y;
    bool is_falling;
};

void draw_blocks(OBJ_ATTR *obj_buffer, Game *game);

Block* get_block(int map_x, int map_y, Block *blocks, int num_blocks);

#endif //BLOCKPERSON_OBJECTS_H
