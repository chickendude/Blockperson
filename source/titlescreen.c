#include "titlescreen.h"
#include "game.h"
#include "levels.h"
// Tile data
#include "pause_screen.h"
#include "title_screen.h"

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void show_titlescreen(Game *game)
{
    memcpy32(&tile_mem[1][1], title_screenTiles, title_screenTilesLen / 4);
    REG_DISPCNT |= DCNT_BG2;

    while(!key_released(KEY_START)) {
        vid_vsync();
        key_poll();
    }

    REG_DISPCNT &= ~DCNT_BG2;
    memcpy32(&tile_mem[1][1], pause_screenTiles, pause_screenTilesLen / 4);
}

// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------