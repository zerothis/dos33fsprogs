; VMW Productions 2018 XMAS Demo
;
; by deater (Vince Weaver) <vince@deater.net>

.include "zp.inc"
.include "hardware.inc"

; external routines

;play_music=$1000
;mockingboard_init=$1100
;mockingboard_mute=$11a1


xmas2018_start:				; this should end up at $4000

	;===================
	; Check for Apple II and patch
	;===================

	lda	$FBB3		; IIe and newer is $06
	cmp	#6
	beq	apple_iie

;	lda	#$54		; patch the check_email font code
;	sta	ce_patch+1


apple_iie:

	;===================
	; Init RTS disk code
	;===================

	jsr	rts_init

	;===================
	; Load graphics
	;===================

	; load WREATH.LZ4 to $a000

	lda	#<wreath_filename
	sta	namlo
	lda	#>wreath_filename
	sta	namhi
	jsr	opendir		; open and read entire file into memory

	; decompress to $2000
	; decompress from $a000
	; size in ???


	lda     #<($a000+11)
	sta     LZ4_SRC
	lda     #>($a000+11)
	sta     LZ4_SRC+1

	lda	#<($a000+4103-8)	; skip checksum at end
;	lda	ldsizel
	sta	LZ4_END
	lda	#>($a000+4103-8)	; skip checksum at end
;	lda	ldsizeh
;	clc
;	adc	#$a0
	sta	LZ4_END+1

	lda	#<$2000
	sta	LZ4_DST
	lda	#>$2000
	sta	LZ4_DST+1

	jsr	lz4_decode



	;==================
	; Init mockingboard
	;==================

	lda	#0
	sta	MB_PATTERN
	lda	#$60
	sta	MB_FRAME

	jsr	mockingboard_init

	;===================
	; set graphics mode
	;===================
	jsr	HOME

	jsr	wreath

	jsr	ball

	jsr	merry

	;==================
	; Game over
	;==================
	; we never get here
game_over_man:
	jmp	game_over_man


.align $100
	.include	"wreath.s"
	.include	"ball.s"
	.include	"merry.s"
	.include	"lz4_decode.s"
	.include	"rts.s"
	.include	"gr_offsets.s"
	.include	"gr_hline.s"
	.include	"gr_fast_clear.s"
	.include	"vapor_lock.s"
	.include	"delay_a.s"
	.include	"wait_keypress.s"
	.include	"mockingboard.s"
;	.include	"random16.s"
;	.include	"hgr.s"
;	.include	"move_letters.s"
	.include	"gr_putsprite.s"
;	.include	"text_print.s"
;	.include	"screen_split.s"

;============================
; Include Sprites
;============================
;.align $100
;	.include "tfv_sprites.inc"
;	.include "mode7_sprites.inc"

;=================================
; Include Text for Sliding Letters
;  *DONT CROSS PAGES*
;=================================
;.include "letters.s"

;============================
; Include Lores Graphics
; No Alignment Needed
;============================

;============================
; Include Hires Graphics
; No Alignment Needed
;   FIXME: we can save 8 bytes per file by stripping checksums off end
;============================

;wreath_hgr:
;.incbin "wreath.img.lz4",11
;wreath_hgr_end:

;ball_hgr:
;.incbin "ball.img.lz4",11
;ball_hgr_end:

;merry_hgr:
;.incbin "merry.img.lz4",11
;merry_hgr_end:



; filename to open is 30-character Apple text:
wreath_filename:	;.byte "WREATH.LZ4                    "
       .byte 'W'|$80,'R'|$80,'E'|$80,'A'|$80,'T'|$80,'H'|$80,'.'|$80,'L'|$80
       .byte 'Z'|$80,'4'|$80,$A0,$A0,$A0,$A0,$A0,$A0
       .byte $A0,$A0,$A0,$A0,$A0,$A0,$A0,$A0
       .byte $A0,$A0,$A0,$A0,$A0,$A0
