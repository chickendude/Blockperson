#include "levels.h"
#include "game.h"

const Level level_1 = {20, 8,
                   120, 0,
                   "B                  B"
                   "B                  B"
                   "B                  B"
                   "B                  B"
                   "B                  B"
                   "B  B        B      B"
                   "BD B    B O B O M  B"
                   "BBBBBBBBBBBBBBBBBBBB"};

// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------
void load_level(Game *game, const Level *level)
{
    game->num_blocks = 0;
    game->cur_level = level;
    game->camera.x = level->start_x;
    game->camera.y = level->start_y;
}


// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------