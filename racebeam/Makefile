include ../Makefile.inc

DOS33 = ../dos33fs-utils/dos33
B2D = ../bmp2dhr/b2d
PNG_TO_40x48D = ../gr-utils/png_to_40x48d

all:	racebeam.dsk

racebeam.dsk:	HELLO RACEBEAM
	$(DOS33) -y racebeam.dsk SAVE HELLO
	$(DOS33) -y racebeam.dsk BSAVE -a 0x1000 RACEBEAM



####

RACEBEAM:	racebeam.o
	ld65 -o RACEBEAM racebeam.o -C ../linker_scripts/apple2_1000.inc

racebeam.o:	racebeam.s
	ca65 -o racebeam.o racebeam.s -l racebeam.lst


#background_final.inc:	background_final.png
#	$(PNG_TO_40x48D) asm background_final.png bg_final > background_final.inc


####

HELLO:	hello.bas
	../asoft_basic-utils/tokenize_asoft < hello.bas > HELLO

clean:		
		rm -f *~ *.o *.lst *.inc RACEBEAM HELLO
