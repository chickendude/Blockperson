
//{{BLOCK(win_screen)

//======================================================================
//
//	win_screen, 160x64@4, 
//	+ palette 256 entries, not compressed
//	+ 160 tiles not compressed
//	Total size: 512 + 5120 = 5632
//
//	Time-stamp: 2021-09-17, 17:19:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WIN_SCREEN_H
#define GRIT_WIN_SCREEN_H

#define win_screenTilesLen 5120
extern const unsigned int win_screenTiles[1280];

#define win_screenPalLen 512
extern const unsigned short win_screenPal[256];

#endif // GRIT_WIN_SCREEN_H

//}}BLOCK(win_screen)
