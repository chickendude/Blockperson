
@{{BLOCK(title_screen)

@=======================================================================
@
@	title_screen, 160x64@4, 
@	+ palette 256 entries, not compressed
@	+ 160 tiles not compressed
@	Total size: 512 + 5120 = 5632
@
@	Time-stamp: 2021-09-15, 16:55:08
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global title_screenTiles		@ 5120 unsigned chars
	.hidden title_screenTiles
title_screenTiles:
	.word 0x00000000,0xB0000000,0xBB000000,0xABB00000,0xAABB0000,0xAAABB000,0xAAAABB00,0xAAAAABB0
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xA222AAAA,0x2222222A
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xA2AAAAAA,0x222AAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA

	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA

	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBBBBBBB,0xBBBBBBBB,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x00000000,0x0000000B,0x000000BB,0x00000BBA,0x0000BBAA,0x000BBAAA,0x00BBAAAA,0x0BBAAAAA
	.word 0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB
	.word 0xAAAAAAAA,0x22AAAAAA,0x222AAAAA,0x222AAAAA,0x222AAAAA,0x222AAAAA,0x222AAAAA,0x222AAAAA
	.word 0x22222222,0x22222222,0x222AA222,0x22AAAAA2,0x222AAAAA,0x2222AAAA,0xA22222AA,0x2222222A
	.word 0x222AAAAA,0x222AAAA2,0x222AAAA2,0x222AAAA2,0x222AAAA2,0x222AAAAA,0x222AAAAA,0x222AAAAA

	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAA2
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0x2AAAAAAA,0x22AAAAAA,0x22AAAAAA,0x22AAAAAA,0x22AAAAAA,0x22AAAAAA,0x22AAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAA2,0xAAAAAAA2,0xAAAAAAA2,0xAAAAAAA2,0xA22AAAA2,0x2222AAA2
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0x2AAAAAAA,0x22AAAAAA,0x22AAAAAA,0x22AAAAAA,0x22AAAAAA,0x22AAAAAA
	.word 0xA222222A,0x22222222,0x22222222,0x222AAA22,0x22AAAAA2,0x22AAAAA2,0x22AAAAA2,0x22AAAAA2
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAA2,0xAAAAAAA2,0xAAAAAAA2,0x22AAAAA2,0x222AAAA2

	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0x2AAAA222,0x2AAA2222
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAA2,0x222222A2,0x22222222
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0x222AAAAA,0x2222AAA2
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAA2,0xAAAAAA22
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAA2
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA

	.word 0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB
	.word 0x222AAAAA,0x222AAAAA,0x22AAAAAA,0x22AAAAAA,0x22AAAAAA,0x22AAAAAA,0x22AAAAAA,0x22AAAAAA
	.word 0x222222AA,0x22AAAAA2,0x2AAAAAA2,0xAAAAAAA2,0xAAAAAAA2,0xAAAAAAA2,0xAAAAAAA2,0x2AAAAAA2
	.word 0x22AAAAA2,0x22AAAA22,0x22AAA222,0x22AAA222,0x22AAA222,0x22AAA222,0x222AA222,0x222AA222
	.word 0x22AAAAA2,0x2222AAA2,0x22222AA2,0xAA222AA2,0xAA2222A2,0xAAA222A2,0xAAA222A2,0xAAA222A2
	.word 0xAAAAAAA2,0xAAAAAA22,0x2AAAA222,0x22AAA222,0x22AA222A,0x222A222A,0x222A2222,0x222AA222
	.word 0x2AAAAAAA,0x2AAAA222,0x2AAA2222,0x2AAAA222,0x2AAAAAA2,0x2A2AAAAA,0x2A222AAA,0x2A2222A2
	.word 0xA2222A22,0xAA222222,0xAAA22222,0xAAAA2222,0xAAAA2222,0xAAA22222,0xAA222222,0xA2222A22

	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x22AAAAAA,0x22AAAAAA,0x22AAAAAA,0x2222AAAA,0x22222AAA,0x2222AAAA,0x22AAAAAA,0x22AAAAAA
	.word 0x22AAAAA2,0x222AAAA2,0x222222A2,0xA2222222,0xAAA22222,0xAAAAA222,0xAAAAAAA2,0xAAAAAAA2
	.word 0x2222AAA2,0x22222AA2,0xAA2222AA,0x222222AA,0x2222222A,0x2222222A,0xAAAA222A,0xAAA2222A
	.word 0x2AA22222,0x2AA22222,0x2AA222AA,0x2AA22222,0x2AAA2222,0x2AAAA222,0x2AAAAAAA,0x2AAA2AAA
	.word 0x22222222,0x22AAA222,0xAAAAA222,0xAAAAA222,0xAAAAAA22,0xAAAAAA22,0xAAAAAA22,0xAAAAAA22
	.word 0x22222AA2,0xAA2222AA,0xAAA222AA,0xA22222AA,0x22222AAA,0x2222AAAA,0x222AAAAA,0x222AA2AA
	.word 0x2AAAA222,0x22AAAA22,0x2222AAAA,0x22222AAA,0xA22222AA,0xAA2222AA,0xAA2222AA,0xAA222AAA

	.word 0x2AAAA222,0x2AAA2222,0x2AA22222,0x2A222222,0x2A222222,0x2A22222A,0xAA22222A,0xAAA2222A
	.word 0xA222AA22,0x22222222,0x22222222,0x22222222,0xAAAA2222,0xAAAAA222,0xAAAAA222,0xAAAAA222
	.word 0xAAAAAAAA,0xAAAAAAA2,0xAAAAAA22,0xAAAAA222,0xAAAAA222,0xAAAA2222,0xAAAA222A,0xAAAA222A
	.word 0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA
	.word 0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB
	.word 0x222AAAAA,0x222AAAAA,0x22AAAAAA,0x22AAAAAA,0x22AAAAAA,0x22AAAAAA,0x2AAAAAAA,0xAAAAAAAA
	.word 0x222AAAA2,0x22222222,0x22222222,0xAA222222,0xAAAAAAA2,0xAAAAAAA2,0xAAAAAAAA,0xAAAAAAAA
	.word 0x222AA222,0x222AAA22,0x2AAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA

	.word 0x222222A2,0x22222AA2,0x2222AAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x22AAA222,0x2AAAAA22,0xAAAAAAA2,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x2AA22222,0x2AAA2222,0xAAAAAA22,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x2222AA22,0x222AAAA2,0x22AAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAA2,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x222AAAAA,0x222AAAAA,0xA2AAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAA2,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x222222AA,0x22222AAA,0x2222AAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA

	.word 0x2AA22222,0x2AA22222,0xAAAA2222,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAA22,0xAAAAAA22,0xAAAAAAA2,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x2222222A,0xA222222A,0xAA2222AA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x22222AAA,0x22222AAA,0x2222AAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAA22222,0xAAAA2222,0xAAAAAA22,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAA222,0xAAAAA222,0xAAAAAA2A,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAA222A,0xAAAA222A,0xAAAAA2AA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA

	.word 0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0x6AAAAAAA,0x6AAAAAAA,0x66AAAAAA,0x666AAAAA,0x6666AAAA,0xA666AAAA
	.word 0xAAAAAAAA,0xAAAAAA66,0x66AAA666,0x666AAA66,0x666AAA66,0xA66AAAA6,0xA66AAAAA,0xA66AAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAA6666,0xAAAA6666,0xAAA666AA,0xAAA666AA,0xAA666AAA,0xAA666AAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0x66AAAAAA

	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAA6
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAA666
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0x66AAAAAA,0x666AAAAA,0x666AAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAA666666,0xAA666666,0xAAAAAA66,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAA66
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0x66AAAAAA

	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0x6AAAAAAA,0x6AAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAA6
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAA6,0xAAAAAA66,0xAAAAA666,0xAAAA6666,0xAAA6666A,0xAAA6666A
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA
	.word 0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0x6AAAAAAA,0x6AAAAAAA,0x6AAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAA6666AA,0xAAA6666A,0xAAAA6666,0xAAAAA666,0xAAAAAA66,0xAAAAA666,0xAAAAA666,0xAAAA6666
	.word 0xA66AAAAA,0x666AAAAA,0x666AAAAA,0xA66AAAAA,0xA66AAAAA,0xA66AAAAA,0xA66AAAAA,0xA666AAAA

	.word 0xAAA6666A,0xAAA66666,0xAAAAA666,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x66AAAAAA,0x666AA66A,0x6666666A,0xAA66666A,0xAAA6666A,0xAAAA666A,0xAAAA666A,0xAAAA666A
	.word 0xAAAAAAA6,0x66666AA6,0x666666A6,0x6AA666AA,0x66AA66AA,0x666A66AA,0x666666AA,0xA66666AA
	.word 0x6666AAAA,0xA666AAA6,0xAA666AA6,0x66666AA6,0x6666AAA6,0x666AAAA6,0xAAAAAAAA,0xAAAAAAAA
	.word 0x66AAAA66,0x666AAAAA,0x6666AAAA,0x6666AAA6,0x666AAA66,0x66AAA666,0x6AAAA666,0xAAAAA66A
	.word 0xAAAA6666,0xAAAAAAA6,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAA66,0xAAAAA666,0xAAAAA666,0xAAAAA666
	.word 0xA66AAAAA,0xA66AAAAA,0x666AAAAA,0x666AAAAA,0x66AAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAA66,0x666AA666,0x666A666A,0xAAAA666A,0xAAAA666A

	.word 0xAAAAAA66,0xAAAAAA66,0x6AAAAA66,0x6AAAAA66,0x6A666666,0x6AA66666,0x6AAAAA66,0x6AAAAA66
	.word 0xAAAAAAAA,0xAA666666,0xAA666666,0xA666AA66,0xA666AAA6,0xA666AAA6,0xA666AAA6,0xA6666A66
	.word 0xAAAAAAAA,0x6AAA66AA,0x66AA66AA,0x666666AA,0xA66666AA,0xAA6666AA,0xAAA666AA,0xAAA66AAA
	.word 0x66AAAAAA,0x66AAAAA6,0x66AAA666,0x66AAAAA6,0x666666AA,0x666666AA,0x66A666AA,0x66AAAAAA
	.word 0xAAAAAAA6,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAA66666,0xAAAA6666,0xAAAA6666,0xAAAAAAA6
	.word 0xAA6666AA,0xA6666AAA,0x6666AAAA,0x666AAAAA,0x66AAAAAA,0x66AAAAAA,0x666AAAAA,0x666AAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAA6,0xAAAAAAA6,0xAAAAAAA6,0xAAAAAAA6,0xAAAAAAAA
	.word 0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA

	.word 0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAAABB,0xAAAAABB0,0xAAAABB00,0xAAABB000,0xAABB0000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAA6666A,0xAAA666AA,0xAA6666AA,0xAA666AAA,0xA666AAAA,0x6666AAAA,0x666AAAAA,0xA6AAAAAA
	.word 0xA666AAAA,0xAA66AAAA,0xAA66AAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAA666A,0xAAAA666A,0xAAAAA66A,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x666666AA,0x66666AAA,0x666AAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xA66AAA66,0x666AAA66,0x66AAAAA6,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA

	.word 0x6A66A666,0x6666A666,0xA66AAAA6,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAAA666,0xAAAAAA66,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xA66AAAAA,0x666AAAAA,0x666AAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAAA6666,0xAAAAA666,0xAAAAAA66,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x6AAAA666,0xAAAA6666,0xAAAA666A,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x66666666,0x66666666,0x666A6666,0x66AAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xAAA66AA6,0xAA666AAA,0xAA666AAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x66AAAAAA,0x66AAAAAA,0x66AAAAAA,0x66AAAAAA,0x6AAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA

	.word 0xAAAAAAA6,0xAAAAAAA6,0xAAAAA666,0xAAAAA666,0xAAAAAAA6,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0x666AAAAA,0xA666AAAA,0xA6666AAA,0xAA6666AA,0xAAA666AA,0xAAAA666A,0xAAAAA6AA,0xAAAAAAAA
	.word 0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA,0xAAAAAAAA
	.word 0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0xBBAAAAAA,0x0BBAAAAA,0x00BBAAAA,0x000BBAAA,0x0000BBAA
	.word 0xABB00000,0xBB000000,0xB0000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0xAAAAAAAA,0xAAAAAAAA,0xBBBBBBBB,0xBBBBBBBB,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000BBA,0x000000BB,0x0000000B,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global title_screenPal		@ 512 unsigned chars
	.hidden title_screenPal
title_screenPal:
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

@}}BLOCK(title_screen)
