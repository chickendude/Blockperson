#include "game.h"
#include "constants.h"
#include "levels.h"

//------------------------------------------------------------------------------
// Constants and macros
//------------------------------------------------------------------------------
#define TILE(n) (n * 4 + 1)

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------
void draw_tile(int x, int y, int tile_id);

// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------

void draw_tilemap(Game *game)
{
    int start_x = game->camera.x;
    int start_y = game->camera.y;
    const char *map = game->cur_level->tilemap;
    game->num_blocks = 0;
    se_fill(&se_mem[30][0], 0);
    se_fill(&se_mem[31][0], 0);
    start_x /= TILE_SIZE;
    start_y /= TILE_SIZE;
    for (int x = 0; x < (256 / TILE_SIZE); x++)
    {
        for (int y = 0; y < (256 / TILE_SIZE); y++)
        {
            switch (map[(y + start_y) * 20 +
                        (x + start_x)])
            {
                case 'B':
                    draw_tile(x, y, TILE(0));
                    break;
                case 'D':
                    // tile id 2, 4 sprites per tile (16x16), skip first
                    // (empty) tile
                    draw_tile(x, y, TILE(2));
                    break;
                case 'O':
                    game->blocks[game->num_blocks].x = (x + start_x) * TILE_SIZE;
                    game->blocks[game->num_blocks].y = (y + start_y) * TILE_SIZE;
                    game->num_blocks++;
                    break;
            }
        }
    }
}


// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------
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

