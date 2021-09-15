#include "levels.h"
#include "game.h"

const Level *levels[5] = {&level_1, &level_2, &level_3, &level_4, &level_5};

const Level level_1 = {20, 10,
                       80, 0,
                       "                    "
                       "                    "
                       "B                  B"
                       "B                  B"
                       "B                  B"
                       "B                  B"
                       "B                  B"
                       "B  B        B      B"
                       "BD B    B O B O M  B"
                       "BBBBBBBBBBBBBBBBBBBB"};

const Level level_2 = {22, 10,
                       112, 0,
                       " B    BB        BB    "
                       " B                B   "
                       "BB                 B  "
                       "BD                  B "
                       "BB                   B"
                       " B           B  O    B"
                       " B           BO OOM  B"
                       " BBBBB   BBBBBBBBBBBBB"
                       "     B  OB            "
                       "     BBBBB            "};

const Level level_3 = {19, 11,
                       24, 16,
                       " B                 "
                       " B   BBBBBBBBBBBBB "
                       "B B B             B"
                       "B  B              B"
                       "B                OB"
                       "B               OOB"
                       "B BBB    M   BO BB "
                       "B B B    B  BBBBB  "
                       "B B BOO BB  B      "
                       "BDB BBBBBB BB      "
                       "BBB BB   BBB       "};

const Level level_4 = {24, 16,
                       144, 64,
                       "                  B     "
                       "                 B B    "
                       "       B        B   B   "
                       "      B B      B     B  "
                       "   BBB   B    B       B "
                       "  B       B  B         B"
                       " B         BB          B"
                       " B                    OB"
                       " B                   OOB"
                       " B               M   BBB"
                       "BB    B          B   B  "
                       "BD    B O        BBBBB  "
                       "BBBBB B O   O  BBB      "
                       "    B B O B BO B        "
                       "    B BBBBBBBBBB        "
                       "    BBB                 "};

const Level level_5 = {22, 14,
                       72, 48,
                       "     BBB    BBBBBBBBB "
                       " BBBB   BBBB         B"
                       "B                    B"
                       "B                    B"
                       "B                    B"
                       "B     B              B"
                       "B     B              B"
                       "B     BOOOO          B"
                       "BD   BBBBBBBM        B"
                       "BB BBB     BB B     OB"
                       " B B        B BB   OOB"
                       " B B        B BB  OOOB"
                       " BBB        B BBBBBBBB"
                       "            BBB       "};
// -----------------------------------------------------------------------------
// Private function declarations
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Public function definitions
// -----------------------------------------------------------------------------
void load_next_level(Game *game, OBJ_ATTR *obj_buffer)
{
    const Level *level = levels[game->level_id++];
    game->num_blocks = 0;
    game->cur_level = level;
    game->camera.x = level->start_x;
    game->camera.y = level->start_y;
    game->player.animation_frames = 0;
    game->player.state = IDLE;
    game->player.lifted_block = NULL;

    extract_tilemap(game);
    vid_vsync();
    draw_tilemap(game);
    draw_blocks(obj_buffer, game);
    REG_BG0HOFS = game->camera.x;
    REG_BG0VOFS = game->camera.y;

    // Background (parallax scrolling)
    REG_BG1HOFS = game->camera.x >> 3;
    REG_BG1VOFS = game->camera.y >> 3;
}


// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------