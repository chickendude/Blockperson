#ifndef BLOCKPERSON_CAMERA_H
#define BLOCKPERSON_CAMERA_H

#include "types.h"

struct Camera
{
    int x, y;
    int dx, dy;
};

void update_camera(Game *game);

#endif //BLOCKPERSON_CAMERA_H
