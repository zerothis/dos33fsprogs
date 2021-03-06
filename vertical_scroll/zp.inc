;; Zero Page

;; LZ4 addresses

LZ4_SRC		= $00
LZ4_DST		= $02
LZ4_END		= $04
WHICH_LOAD	= $05
COUNT		= $06
MENU_BASE	= $06
MENU_HIGHLIGHT	= $07
DELTA		= $08


;; Zero page monitor routines addresses

WNDLFT	= $20
WNDWDTH	= $21
WNDTOP	= $22
WNDBTM	= $23
CH	= $24
CV	= $25
GBASL	= $26
GBASH	= $27
BASL	= $28
BASH	= $29
H2	= $2C
V2	= $2D
MASK	= $2E
COLOR_MASK = $2F
COLOR	= $30


SEEDL	= $4e
SEEDH	= $4f

AY_REGISTERS	= $70
A_FINE_TONE	= $70
A_COARSE_TONE	= $71
B_FINE_TONE	= $72
B_COARSE_TONE	= $73
C_FINE_TONE	= $74
C_COARSE_TONE	= $75
NOISE		= $76
ENABLE		= $77
PT3_MIXER_VAL	= $77
A_VOLUME	= $78
B_VOLUME	= $79
C_VOLUME	= $7A
ENVELOPE_FINE	= $7B
ENVELOPE_COARSE	= $7C
ENVELOPE_SHAPE  = $7D

PATTERN_L       = $7E
PATTERN_H       = $7F
ORNAMENT_L      = $80
ORNAMENT_H      = $81
SAMPLE_L        = $82
SAMPLE_H        = $83

LOOP            = $84
MB_VALUE        = $85
MB_ADDR_L	= $86
MB_ADDR_H	= $87
DONE_PLAYING    = $88
DONE_SONG       = $89
PT3_TEMP	= $8A



DISP_PAGE	=	$ED	; ALL
DRAW_PAGE	=	$EE	; ALL


TINL		=	$F0
TINH		=	$F1
BINL		=	$F2
BINH		=	$F3


SCROLL_COUNT	=	$F9
TEMP		=	$FA
TEMPY		=	$FB
INL		=	$FC
INH		=	$FD
OUTL		=	$FE
OUTH		=	$FF
