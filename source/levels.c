#include "levels.h"
#include "game.h"

const Level *levels[11] = {&level_1, &level_2, &level_3, &level_4, &level_5,
                           &level_6, &level_7, &level_8, &level_9, &level_10,
                           &level_11};

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
const Level level_6 = {21, 13,
                       88, 32,
                       " BBB             BBBB"
                       " B  BBBBBBBBBBBBB   B"
                       "BB                  B"
                       "BD                  B"
                       "BB                  B"
                       " B                OOB"
                       " BOO        B  O  BBB"
                       " BOOO       BMOOO B  "
                       " BOOOO      BBBBB B  "
                       " BBBBB    BBB   BBB  "
                       "     B   OB          "
                       "     BB BBB          "
                       "      BBB            "
};

const Level level_7 = {24, 14,
                       144, 64,
                       "  B   BBBBB   BB   BBB  "
                       " B B B     B B  B B   B "
                       " B  BB      BB   BB    B"
                       " B   B       B    B    B"
                       " B                    OB"
                       " B                    OB"
                       "BB                   OOB"
                       "BD   O               BBB"
                       "BB   B O     B    BB B  "
                       " B   B O    BB O MBBBB  "
                       " BB  B OOO  BB OOOB     "
                       "  B  BBBBBB BBBBBBB     "
                       "  BB B    BBB           "
                       "   BBB                  "
};

const Level level_8 = {
        27, 17,
        192, 112,
        " BBB       BBBB   BBBBBBB  "
        "B   B     B    B B       B "
        "B    B   B     BB         B"
        "BO    BBB    B B     BBB  B"
        "BOO         BB      BB B  B"
        "BBBB       BB          BD B"
        "   BB            BB    BB B"
        "  B    O B      B  B      B"
        "  B    OB B    B   B      B"
        " B   BBB   B    B  B     OB"
        " B      B B      BB     OOB"
        "B        B           BBBBBB"
        "B            O            B"
        "B    O      BBB          OB"
        "B   BBB                 OOB"
        "B        O       O  M  OOOB"
        "BBBBBBBBBBBBBBBBBBBBBBBBBBB"
};

const Level level_9 = {
        20, 16,
        80, 32,
        "        BBB         "
        "       B   B        "
        "      B     B  BBBBB"
        "     B       BB    B"
        "    B     O        B"
        "   B      OO      OB"
        "  B       BBB    OOB"
        " B            M BBBB"
        "B             O    B"
        "BD           BBB   B"
        "BB    BB   B      OB"
        " B    BBO  BB   BBBB"
        " B    BBBBBBB  BB   "
        " BBB  B     B BB    "
        "   B BB     BBB     "
        "   BBB              "
};

const Level level_10 = {
        27, 19,
        104, 96,
        "   BBBBBBBBBBBBBBBBBBBBB   "
        " BB           B         B  "
        "BBBBO       OOBO   OOO OBB "
        "B  BB  B   BBBBB  OBBB BB B"
        "B   B  BB        BBB BBB  B"
        "B   BB  BBOOOO            B"
        "BD       BBBBBBB          B"
        "BB        B   BBB        BB"
        " B     O   B B  BB        B"
        " B     B    B    BB       B"
        " BBBB  BB             BBBBB"
        "   BBBBB      M           B"
        "   B          B           B"
        "   B         BB    BBBBBBBB"
        "   B        BB           B "
        "   B          O         OB "
        "   BO    BBBBBBBBBBB   OOB "
        "   BOO  BB         BB OOOB "
        "   BBBBBB           BBBBBB "
};

const Level level_11 = {
        29, 19,
        88, 0,
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
        "B  B   B                    B"
        "B     OBOO            BBBBB B"
        "BO   BBB OBB     O  BB  D B B"
        "BOO    BBB   M  O       B B B"
        "BBB  OOB     B O          B B"
        "B   BBBB      B  BBB   BBB  B"
        "BO            B B      B  O B"
        "BOO       BBB B BO    B  BBBB"
        "BBBB O   BBB  B BBO  B O B  B"
        "B           O BBB  OB   B   B"
        "B   O     OO B   BBBB       B"
        "B    BBBBBBBBB        BBBBB B"
        "B              O   OBB    B B"
        "BBBB           O   B    OOB B"
        "BOBB   B    B          BBBB B"
        "BBOBBB B    B   OOO O       B"
        "BOBOBOBB    B        OOO    B"
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
};

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

    // Load new tilemap
    extract_tilemap(game);

    // Update VRAM data
    vid_vsync();
    draw_tilemap(game);
    draw_blocks(obj_buffer, game);

    // Hide all blocks
    for (int i = 0; i < 50; i++)
    {
        obj_set_pos(&oam_mem[i + 1], -16, -16);
    }

    // Foreground camera
    REG_BG0HOFS = game->camera.x;
    REG_BG0VOFS = game->camera.y;

    // Background (parallax scrolling)
    REG_BG1HOFS = game->camera.x >> 3;
    REG_BG1VOFS = game->camera.y >> 3;
}


// -----------------------------------------------------------------------------
// Private functions definitions
// -----------------------------------------------------------------------------