cmake_minimum_required(VERSION 3.19)
project(blockperson C)

set(CMAKE_C_STANDARD 99)

# Specify external includes here
include_directories($ENV{DEVKITARM}/include/)
include_directories($ENV{DEVKITPRO}/libgba/include/)
include_directories($ENV{DEVKITPRO}/libtonc/include/)
include_directories($ENV{DEVKITARM}/arm-none-eabi/include)
include_directories(include gfx)

add_executable(blockperson source/main.c source/levels.c source/objects.c source/game.c include/player.h source/player.c source/camera.c gfx/bg.h include/titlescreen.h source/titlescreen.c)