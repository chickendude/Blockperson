
@{{BLOCK(win_screen)

@=======================================================================
@
@	win_screen, 160x64@4, 
@	+ palette 256 entries, not compressed
@	+ 160 tiles not compressed
@	Total size: 512 + 5120 = 5632
@
@	Time-stamp: 2021-09-17, 17:19:44
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global win_screenTiles		@ 5120 unsigned chars
	.hidden win_screenTiles
win_screenTiles:
	.word 0x00000000,0xD0000000,0xDD000000,0xEDD00000,0xEEDD0000,0xEEEDD000,0xEEEEDD00,0xEEEEEDD0
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEFFEEEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE

	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE

	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDDDDDDD,0xDDDDDDDD,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0x00000000,0x0000000D,0x000000DD,0x00000DDE,0x0000DDEE,0x000DDEEE,0x00DDEEEE,0x0DDEEEEE
	.word 0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD
	.word 0xEEEEEEEE,0xEEEEFFEE,0xEEEFFFFE,0xEEEFFFFE,0xEEEFFFFE,0xEEEFFFFE,0xEEEFFFFE,0xEEEFFFFE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE

	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEF,0xEEEEEEEF,0xEEEEEEEF
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE

	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEFFEEEE,0xEFFFFEEE,0xEFFFFEEE,0xEFFFFEEE
	.word 0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE

	.word 0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD
	.word 0xEEEFFFFE,0xEEEFFFFE,0xEEEFFFFE,0xEEEFFFFF,0xEEEFFFFF,0xEEEEFFFF,0xEEEFFFFF,0xEEEFFFFF
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xFFFFFEEE,0xFFFFFEEE,0xFFFFFEEE,0xFFFFFFEE,0xFFFFFFEE,0xFFFFFFEE,0xFFFFFFFE,0xFFFFFFFF
	.word 0xEEEEEEEF,0xEEEEEEEF,0xEEEEEEEF,0xEEEEEEEF,0xEEEEEEEF,0xEEEEEEEF,0xEEEEEEEF,0xEEEEEEEF
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE

	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEFFE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEFFEEE,0xEEFFFFEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xFFFEEEEE,0xFFFFEEEE,0xFFFFFEEE,0xFFFFFEEE,0xFFFFFEEE,0xFFFFFEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEF,0xEEEEEEEF,0xEEEEEEEF,0xEEEEEEEF,0xEEEEEEEF

	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEFFFFEEE,0xEFFFFFEE,0xEFFFFFEE,0xEEFFFFEE,0xEEFFFFEE,0xEEFFFFEE,0xEEFFFFEE,0xEEFFFFEE
	.word 0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE
	.word 0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD
	.word 0xEEEFFFFE,0xEEFFFFFE,0xEEFFFFFE,0xEFFFFFEE,0xFFFFFFEE,0xFFFFFEEE,0xFFFFEEEE,0xFFFEEEEE
	.word 0xFEEEEEEE,0xFFEEEEEE,0xFFFEEEEE,0xFFFFEEEE,0xFFFFFFFF,0xFFFFFFFF,0xEFFFFFFF,0xEEFFFFFF
	.word 0xFFFFFFFF,0xFFFFFFFF,0xFFFEFFFF,0xFFFEEEFF,0xFFEEEEEF,0xFFEEEEEE,0xFFEEEEEE,0xFFEEEEEE

	.word 0xEEEEEEEF,0xEEEEEEEF,0xEEEEEEFF,0xEEEEEEFF,0xEEEEEEFF,0xEEEEEEFF,0xEEEEEEFF,0xEEEEEEFF
	.word 0xEEEEEEEE,0xFEEEEEEE,0xFFEEEEEE,0xFFFEEEEE,0xFFFFEEEE,0xFFFFFEEE,0xFFFFFFEE,0xEFFFFFEE
	.word 0xEEEEEEEE,0xEEFFFFFF,0xEFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFEF,0xFFFEEEEE,0xFFEEEEEE
	.word 0xEEEEEEEE,0xFEEEEEEE,0xFFEEEEEE,0xFFEEEEEE,0xFFEEEEEF,0xFFEEEEFF,0xFFEEEFFF,0xFFEEFFFF
	.word 0xEEEEEEEE,0xFEEEEEEF,0xFEEEEEFF,0xFEEEEEFF,0xEEEEEEFF,0xEEEEEEFF,0xEEEEEEFF,0xEEEEEFFF
	.word 0xEEEEEEFF,0xEEEEEFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEFFFFF,0xEEEFFFFF,0xEEEFFFFF
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEFFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEFFFFF,0xEEEFFFFE

	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEFFEEE,0xEEEFFFFE,0xEEEFFFFF,0xEEEFFFFF,0xEEEFFFFF,0xEEEFFFFE
	.word 0xEEFFFFEE,0xEEFFFFEE,0xEEFFFFEE,0xEFFFFFEE,0xEFFFFFEE,0xEFFFFEEE,0xEFFFFEEE,0xEFFFFEEE
	.word 0xFFFFEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEFFEEEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEFFEEEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xFFFFFFEE,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFEEEFFFF
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEF,0xEEEEEEFF,0xEEEEEFFF,0xEEEEFFFF,0xEEEEFFFF
	.word 0xEFFFFFEE,0xEFFFFFEE,0xEFFFFEEE,0xFFFFFEEE,0xFFFFFEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE
	.word 0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE

	.word 0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xFFEEEEEE,0xFFEEEEEE,0xFFEEEEEE,0xFEEEEEEE,0xFEEEEEEE,0xFEEEEEEE,0xFEEEEEEE,0xFEEEEEEE
	.word 0xEEEEEFFF,0xEEEEEFFF,0xEEEEEFFF,0xEEEEEFFF,0xEEEEEFFF,0xEEEEEFFF,0xEEEEFFFF,0xEEEEFFFF
	.word 0xEEFFFFEE,0xEEFFFFEE,0xEEFFFFEE,0xEEFFFFEE,0xEEFFFFEE,0xEEFFFFEE,0xEEFFFFEE,0xEFFFFFEE
	.word 0xFEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xFFEEFFFF,0xFFEEFFFF,0xFFEEFFFF,0xFEEEFFFF,0xFEEEFFFF,0xFEEEFFFF,0xEEEEFFFF,0xEEEEFFFF

	.word 0xEEEEEFFF,0xEEEEEFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEFFFFF,0xEEEFFFFF,0xEEEFFFFF
	.word 0xEEFFFFFF,0xEEFFFFFF,0xEFFFFFFE,0xEFFFFFFE,0xEFFFFFFE,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEFFFFE,0xEEEFFFFE,0xEEEFFFFE,0xEEFFFFFE,0xEEFFFFEE,0xEFFFFFEE,0xEFFFFFEE,0xEFFFFEEE
	.word 0xEEEFFFFE,0xEEEFFFFE,0xEEFFFFFE,0xEEFFFFFE,0xEEFFFFEE,0xEFFFFFEE,0xEFFFFFFE,0xEFFFFFFE
	.word 0xEFFFFEEE,0xEFFFFEEE,0xEFFFFEEE,0xEFFFFEEE,0xEFFFFEEE,0xEFFFFEEE,0xEFFFFFEE,0xEFFFFFEE
	.word 0xFFFFEEEE,0xFFFEEEEE,0xFFFEEEEE,0xFFFEEEEE,0xFFFEEEEE,0xFFFEEEEE,0xFFFEEEEE,0xFFFEEEEE
	.word 0xFFFFEEEF,0xFFFEEEEF,0xFFFEEEEF,0xFFFEEEEF,0xFFEEEEEF,0xFFEEEEEF,0xFFEEEEFF,0xFEEEEEFF

	.word 0xEEEEEFFF,0xEEEEEFFF,0xEEEEEFFF,0xEEEEEFFF,0xEEEEEFFF,0xEEEEEFFF,0xEEEEEFFF,0xEEEEEFFF
	.word 0xEEEEFFFF,0xEEEEFFFF,0xEEEFFFFF,0xEEEFFFFE,0xEEEFFFFE,0xEEEFFFFE,0xEEEFFFFE,0xEEEFFFFE
	.word 0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFFEEEE,0xEFFEEEEE,0xEEEEEEEE
	.word 0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE
	.word 0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD
	.word 0xEEEEEEEE,0xFFEEEEEE,0xFFFEEEEE,0xFFFEEEEE,0xFFEEEEEE,0xFEEEEEEE,0xFEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEF,0xEEEEEEFF,0xEEEEEFFF,0xEEEEEFFF,0xEEEEEFFF,0xEEEEFFFF,0xEEEFFFFF
	.word 0xFEEEEEEE,0xFEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xFEEEEEEE,0xFEEEEEEE,0xFEEEEEEE

	.word 0xEEEEFFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEEFFFF
	.word 0xEFFFFFEE,0xFFFFFEEE,0xFFFFFEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFEEEEE,0xFFEEEEEE,0xEEEEEEEE
	.word 0xFEEEEEEE,0xFEEEEEEE,0xFFEEEEEE,0xFFFEEEFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xEFFFFFFF
	.word 0xEEEEFFFF,0xEEEEFFFF,0xEEEEEFFF,0xEEEEEFFF,0xEEEEEEFF,0xEEEEEEEF,0xEEEEEEEE,0xEEEEEEEE
	.word 0xFEFFFFFF,0xFEFFFFFE,0xFFFFFFEE,0xFFFFFFEE,0xFFFFFEEE,0xFFFFEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xFFFFFFFF,0xFFFEFFFF,0xFFFEEFFF,0xFFFEEFFF,0xFFEEEEFF,0xFFEEEEEF,0xFFEEEEEE,0xFEEEEEEE
	.word 0xEEEEEEEF,0xEEEEEEEF,0xEEEEEEFF,0xEEEEEEFF,0xEEEEEEFF,0xEEEEEEFF,0xEEEEEEFF,0xEEEEEEEF
	.word 0xFFFFFEEE,0xFFFFEEEE,0xFFFFEEEE,0xFFFEEEEE,0xFFFEEEEE,0xFFEEEEEE,0xEEEEEEEE,0xEEEEEEEE

	.word 0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFEFFFF,0xFFEEEFFF,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEFFFFEE,0xEEFFFFFE,0xEEFFFFFF,0xEEEFFFFF,0xEEEEFFFF,0xEEEEEFFF,0xEEEEEEEE,0xEEEEEEEE
	.word 0xFFEEEEEE,0xFFEEEEEE,0xFFEEEEEE,0xFFEEEEEE,0xFFEEEEEE,0xFEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xFEEEEEFF,0xFEEEEEFF,0xEEEEEEFF,0xEEEEEEFF,0xEEEEEEFF,0xEEEEEEEF,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEFFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEEFFFF,0xEEEEEFFE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEFFFFF,0xEEEFFFFF,0xEEEFFFFF,0xEEFFFFFF,0xEEFFFFFE,0xEEEFFFEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEFFFEEE,0xEFFFFFEE,0xFFFFFFEE,0xFFFFFFEE,0xFFFFFFEE,0xFFFFFFEE
	.word 0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEF,0xDDEEEEEF,0xDDEEEEEF

	.word 0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEEDD,0xEEEEEDD0,0xEEEEDD00,0xEEEDD000,0xEEDD0000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEFFFFFFF,0xFFFFFFFE,0xFFFFFFEE,0xFFFFFEEE,0xFFFEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xFFEEEEEE,0xFFEEEEFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xEFFFFFFF,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEFFFF,0xEEEEEEFF,0xEEEEEEFF,0xEEEEEEFF,0xEEEEEEEF,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE

	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE

	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xFFFFFFEE,0xFFFFFFEE,0xEFFFFEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE,0xEEEEEEEE
	.word 0xDDEEEEEF,0xDDEEEEEE,0xDDEEEEEE,0xDDEEEEEE,0x0DDEEEEE,0x00DDEEEE,0x000DDEEE,0x0000DDEE
	.word 0xEDD00000,0xDD000000,0xD0000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xEEEEEEEE,0xEEEEEEEE,0xDDDDDDDD,0xDDDDDDDD,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000DDE,0x000000DD,0x0000000D,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global win_screenPal		@ 512 unsigned chars
	.hidden win_screenPal
win_screenPal:
	.hword 0x0000,0x1884,0x1CA8,0x18EC,0x1D51,0x11DB,0x329B,0x4F1D
	.hword 0x1BDF,0x2B93,0x1AED,0x3646,0x15A9,0x112A,0x1CE6,0x38E7
	.hword 0x4186,0x71AB,0x7E6C,0x732B,0x7F79,0x7FFF,0x5AB3,0x41F0
	.hword 0x35AD,0x294B,0x450E,0x18D5,0x315B,0x5DFA,0x2651,0x19B1
	.hword 0x1084,0x1084,0x1084,0x1084,0x1084,0x1084,0x1084,0x1084
	.hword 0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5,0x14A5
	.hword 0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6,0x18C6
	.hword 0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7,0x1CE7

	.hword 0x2108,0x2108,0x2108,0x2108,0x2108,0x2108,0x2108,0x2108
	.hword 0x2529,0x2529,0x2529,0x2529,0x2529,0x2529,0x2529,0x2529
	.hword 0x294A,0x294A,0x294A,0x294A,0x294A,0x294A,0x294A,0x294A
	.hword 0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B,0x2D6B
	.hword 0x318C,0x318C,0x318C,0x318C,0x318C,0x318C,0x318C,0x318C
	.hword 0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD,0x35AD
	.hword 0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE,0x39CE
	.hword 0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF,0x3DEF

	.hword 0x4210,0x4210,0x4210,0x4210,0x4210,0x4210,0x4210,0x4210
	.hword 0x4631,0x4631,0x4631,0x4631,0x4631,0x4631,0x4631,0x4631
	.hword 0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52,0x4A52
	.hword 0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73,0x4E73
	.hword 0x5294,0x5294,0x5294,0x5294,0x5294,0x5294,0x5294,0x5294
	.hword 0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5,0x56B5
	.hword 0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6,0x5AD6
	.hword 0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7,0x5EF7

	.hword 0x6318,0x6318,0x6318,0x6318,0x6318,0x6318,0x6318,0x6318
	.hword 0x6739,0x6739,0x6739,0x6739,0x6739,0x6739,0x6739,0x6739
	.hword 0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A,0x6B5A
	.hword 0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B,0x6F7B
	.hword 0x739C,0x739C,0x739C,0x739C,0x739C,0x739C,0x739C,0x739C
	.hword 0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD,0x77BD
	.hword 0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE,0x7BDE
	.hword 0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF

@}}BLOCK(win_screen)
