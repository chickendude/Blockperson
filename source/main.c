#include "tonc.h"
#include "tiles.h"
//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
#define ROW_TILES 32
#define GAME_SPEED 2

char *map = "B B   B B          B"
            "B  B B   B         B"
            "B   B   B B        B"
            "B                  B"
            "B                  B"
            "B                  B"
            "B                  B"
            "BBBBBBBBBBBBBBBBBBBB";

void draw_tile(int x, int y, int tile_id)
{
    x *= 4;
    y *= 32 * 4;
    for (int i = 0; i < 4; i++)
    {
        int sbb = 30;
        if (x >= 32) sbb = 31;
        se_mem[sbb][y + ((x) & 31)] = tile_id;
        if (x + 1 >= 32) sbb = 31;
        se_mem[sbb][y + ((x + 1) & 31)] = tile_id + 1;
        if (x + 2 >= 32) sbb = 31;
        se_mem[sbb][y + ((x + 2) & 31)] = tile_id + 2;
        if (x + 3 >= 32) sbb = 31;
        se_mem[sbb][y + ((x + 3) & 31)] = tile_id + 3;
        y += ROW_TILES;
        tile_id += 4;
    }
}

void draw_tilemap(int start_x, int start_y)
{
    se_fill(&se_mem[30][0], 0);
    se_fill(&se_mem[31][0], 0);
    start_x /= 32;
    start_y /= 32;
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 6; y++)
        {
            switch (map[(y + start_y) * 20 + (x + start_x)])
            {
                case 'B':
                    draw_tile(x, y, 1);
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
        REG_BG0HOFS = sx % 32;
        REG_BG0VOFS = sy % 32;
        draw_tilemap(sx, sy);

        key_poll();
        sx += key_tri_horz() * GAME_SPEED;
        if (sx < 0) sx = 0;
        if (sx > 20 * 32 - SCREEN_WIDTH) sx = 20 * 32 - SCREEN_WIDTH;
        sy += key_tri_vert() * GAME_SPEED;
        if (sy < 0) sy = 0;
        if (sy > 8 * 32 - SCREEN_HEIGHT) sy = 8 * 32 - SCREEN_HEIGHT;
    };

    return 0;
}
