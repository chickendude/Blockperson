#include <tonc.h>
#include "constants.h"
// Sprite data
#include "tiles.h"

#define TILE(n) (n * 4 + 1)

//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------

char *map = "B                  B"
            "B                  B"
            "B                  B"
            "B                  B"
            "B                  B"
            "B  B        B      B"
            "BD B    B O B O M  B"
            "BBBBBBBBBBBBBBBBBBBB";

void draw_tile(int x, int y, int tile_id)
{
    x *= TILE_SIZE / 8;
    y *= NUM_TILES_IN_ROW * TILE_SIZE / 8;
    int sbb = 30;
    se_mem[sbb][y + ((x) & 31)] = tile_id;
    se_mem[sbb][y + ((x + 1) & 31)] = tile_id + 1;
    se_mem[sbb][y + NUM_TILES_IN_ROW + ((x) & 31)] = tile_id + 2;
    se_mem[sbb][y + NUM_TILES_IN_ROW + ((x + 1) & 31)] = tile_id + 3;
}

void draw_tilemap(int start_x, int start_y)
{
    se_fill(&se_mem[30][0], 0);
    se_fill(&se_mem[31][0], 0);
    start_x /= TILE_SIZE;
    start_y /= TILE_SIZE;
    for (int x = 0; x < (256 / TILE_SIZE); x++)
    {
        for (int y = 0; y < (256 / TILE_SIZE); y++)
        {
            switch (map[(y + start_y) * 20 + (x + start_x)])
            {
                case 'B':
                    draw_tile(x, y, TILE(0));
                    break;
                case 'D':
                    // tile id 2, 4 sprites per tile (16x16), skip first
                    // (empty) tile
                    draw_tile(x, y, TILE(2));
                    break;
            }
        }
    }
}


int main(void)
{
//---------------------------------------------------------------------------------
    // Copy tile and palette data
    memcpy32(&tile_mem[0][1], tilesTiles, tilesTilesLen / 4);
    memcpy32(pal_bg_mem, tilesPal, tilesPalLen / 4);

    draw_tilemap(0, 0);

    // Enable Mode 0: 4 bgs available, but none can be rotated
    REG_DISPCNT = DCNT_MODE0 | DCNT_BG0;

    // Tiles should be at the first character block, maps should be in the last
    // Screen block
    REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_REG_64x32;

    int sx = 0;
    int sy = 0;

    while (1)
    {
        vid_vsync();
        REG_BG0HOFS = sx % 16;
        REG_BG0VOFS = sy % 16;
        draw_tilemap(sx, sy);

        key_poll();
        sx += key_tri_horz() * GAME_SPEED;
        if (sx < 0) sx = 0;
        if (sx > 20 * 16 - SCREEN_WIDTH) sx = 20 * 16 - SCREEN_WIDTH;
        sy += key_tri_vert() * GAME_SPEED;
        if (sy < 0) sy = 0;
        if (sy > 8 * 16 - SCREEN_HEIGHT) sy = 8 * 16 - SCREEN_HEIGHT;
    };

    return 0;
}
