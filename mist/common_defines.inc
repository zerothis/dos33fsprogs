;=============================
; other common stuff

; external routines

opendir_filename = $1039

; audio files

linking_noise	= $9000
LINKING_NOISE_LENGTH = 43


;===============================================
; level data structure definitions
;===============================================
; 24 bytes each location
; we put special at end as it's ignored if not set

LOCATION_NORTH_EXIT=0			; new room when heading north
LOCATION_SOUTH_EXIT=1			; new room when heading south
LOCATION_EAST_EXIT=2			; new room when heading east
LOCATION_WEST_EXIT=3			; new room when heading west
LOCATION_NORTH_EXIT_DIR=4		; direction faced in new room when N
LOCATION_SOUTH_EXIT_DIR=5		; direction faced in new room when S
LOCATION_EAST_EXIT_DIR=6		; direction faced in new room when E
LOCATION_WEST_EXIT_DIR=7		; direction faced in new room when W
LOCATION_NORTH_BG=8			; pointer to north background image
LOCATION_SOUTH_BG=10			; pointer to south background image
LOCATION_EAST_BG=12			; pointer to east background image
LOCATION_WEST_BG=14			; pointer to west background image
LOCATION_BGS	= 16			; bitmap saying which backgrounds valid
	BG_NORTH = 1
	BG_SOUTH = 2
	BG_EAST = 4
	BG_WEST = 8
LOCATION_SPECIAL_EXIT=17		; if we have something clickable
					; $FF if not, direction if so
LOCATION_SPECIAL_X1=18			; collision box for the thing to click
LOCATION_SPECIAL_X2=19
LOCATION_SPECIAL_Y1=20
LOCATION_SPECIAL_Y2=21
LOCATION_SPECIAL_FUNC=22		; pointer-1 of function to call on click


;================================
; Loader definitions

LOAD_TITLE	= $0
LOAD_MIST	= $1
LOAD_MECHE	= $2
LOAD_SELENA	= $3
LOAD_OCTAGON	= $4
LOAD_STONEDSHIP	= $5
LOAD_CHANNEL	= $6
LOAD_ENDING	= $7



;================================
; Level definitions

; Title

TITLE_MIST_LINKING_DOCK	=	0

; Mist

MIST_ARRIVAL_DOCK	=	0
MIST_DOCK_SWITCH	=	1
MIST_DOCK_STEPS		=	2
MIST_ABOVE_DOCK		=	3
MIST_BASE_STEPS		=	4
MIST_STEPS_1ST_LANDING	=	5
MIST_STEPS_2ND_LANDING	=	6
MIST_STEPS_DENTIST	=	7
MIST_STEPS_4TH_LANDING	=	8
MIST_OUTSIDE_TEMPLE	=	9
MIST_POOL		=	10
MIST_CLOCK		=	11
MIST_SPACESHIP_FAR	=	12
MIST_TREE_CORRIDOR_2	=	13
MIST_TREE_CORRIDOR_5	=	14
MIST_GEAR		=	15
MIST_GEAR_BASE		=	16
MIST_DENTIST_DOOR	=	17
MIST_SPACESHIP_SWITCH	=	18
MIST_TREE_CORRIDOR_4	=	19
MIST_TREE_CABIN		=	20
MIST_CLOCK_PUZZLE	=	21
MIST_CLOCK_ISLAND	=	22
MIST_CLOCK_INSIDE	=	23
MIST_OPEN_GEAR		=	24
MIST_CHAIR_VIEW		=	25
MIST_GREEN_SHACK	=	26
MIST_GREEN_STEPS1	=	27
MIST_GREEN_STEPS6	=	28
MIST_GENERATOR_DOOR	=	29
MIST_GENERATOR_ROOM	=	30
MIST_ROCKET_PATH_PAD	=	31
MIST_ROCKET_CLOSE	=	32
MIST_TOWER2_PATH	=	33
MIST_TOWER2_BASE	=	34
MIST_TOWER2_TOP		=	35
MIST_TOWER1_TRAIL	=	36
MIST_TOWER1_TRAIL2	=	37
MIST_TOWER1_BOTTOM	=	38
MIST_TOWER1_TOP		=	39


; Mist Octagon Building

OCTAGON_TEMPLE_DOORWAY	=	0
OCTAGON_TEMPLE_CENTER	=	1
OCTAGON_RED_BOOKSHELF	=	2
OCTAGON_FIREPLACE	=	3
OCTAGON_IN_FIREPLACE	=	4
OCTAGON_CEILING		=	5

; Mechanical Engineering

MECHE_INSIDE_GEAR	=	0
MECHE_CLOSED_BOOK	=	1
MECHE_OPEN_BOOK		=	2
MECHE_ARRIVAL		=	3
MECHE_ENTRANCE		=	4
MECHE_FORT_VIEW		=	5
MECHE_BRIDGE2		=	6
MECHE_FORT_DOOR		=	7
MECHE_FORT_ENTRY	=	8
MECHE_WEST_PLATFORM	=	9
MECHE_NORTH_PLATFORM	=	10
MECHE_NORTH_HINT	=	11
MECHE_NORTH_TOP		=	12
MECHE_NORTH_DIP		=	13

;MECHE_EAST_PLATFORM	=	9


; Selena Age

SELENA_INSIDE_SHIP	=	0
SELENA_CONTROLS		=	1
SELENA_ELECTRIC_ORGAN	=	2
SELENA_WALKWAY1		=	3
SELENA_SPACESHIP_DOOR	=	4
SELENA_WALKWAY4		=	5
SELENA_BUNKER		=	6
SELENA_SUB_ROOM		=	7
SELENA_BOOK_ROOM	=	8
SELENA_BOOK_CLOSED	=	9
SELENA_BOOK_OPEN	=	10