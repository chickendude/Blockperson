#include "levels.h"
#include "game.h"
#include "maps.h"

const Level level_1 = {&map_1};
// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------
void load_level(Game *game, const Level *level)
{
    game->cur_level = level;
    game->camera.x = level->map->start_x;
    game->camera.y = level->map->start_y;
}


// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------