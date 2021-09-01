#ifndef BLOCKPERSON_MAPS_H
#define BLOCKPERSON_MAPS_H

#include "types.h"

struct Map
{
    const int w, h;
    int start_x, start_y;
    const char *tilemap;
};

extern const Map map_1;
#endif //BLOCKPERSON_MAPS_H
