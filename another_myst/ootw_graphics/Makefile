include ../../Makefile.inc

PNG2RLE = ../../gr-utils/png2rle
PNG2LZ4 = ../../gr-utils/png2lz4

all:	ootw_c16_end.inc logo.inc

#####

logo.inc:	$(PNG2RLE) \
	logo.png
	$(PNG2RLE) asm logo.png logo_rle > logo.inc

ootw_c16_end.inc:	$(PNG2RLE) \
	wing_bg.png \
	left_unfurl1.png left_unfurl2.png \
	right_unfurl1.png right_unfurl2.png \
	sky_bg.png \
	rooftop00.png rooftop01.png rooftop02.png rooftop03.png onboard.png \
	flying01.png flying03.png flying05.png flying07.png flying09.png \
	flying11.png \
	the_end01.png the_end02.png the_end03.png the_end04.png the_end05.png \
	the_end06.png the_end07.png the_end08.png the_end09.png the_end10.png \
	east_top_w.png temple_center_w.png temple_center_ex.png \
	generator_n.png approach07.png blank.png \
	ootw_uboot_flash2.png ootw_uboot_flash1.png ootw_uboot_bg.png \
	another_pool.png
	$(PNG2RLE) asm wing_bg.png wing_bg_rle > ootw_c16_end.inc
	$(PNG2RLE) asm left_unfurl1.png left_unfurl1_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm left_unfurl2.png left_unfurl2_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm right_unfurl1.png right_unfurl1_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm right_unfurl2.png right_unfurl2_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm sky_bg.png sky_bg_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm rooftop00.png rooftop0_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm rooftop01.png rooftop1_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm rooftop02.png rooftop2_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm rooftop03.png rooftop3_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm onboard.png onboard_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm flying01.png flying01_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm flying03.png flying03_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm flying05.png flying05_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm flying07.png flying07_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm flying09.png flying09_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm flying11.png flying11_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm the_end01.png the_end01_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm the_end02.png the_end02_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm the_end03.png the_end03_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm the_end04.png the_end04_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm the_end05.png the_end05_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm the_end06.png the_end06_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm the_end07.png the_end07_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm the_end08.png the_end08_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm the_end09.png the_end09_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm the_end10.png the_end10_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm east_top_w.png east_top_w_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm temple_center_w.png temple_center_w_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm temple_center_ex.png temple_center_ex_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm generator_n.png generator_n_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm approach07.png approach07_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm blank.png blank_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm ootw_uboot_bg.png underwater_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm ootw_uboot_flash1.png uboot_flash1_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm ootw_uboot_flash2.png uboot_flash2_rle >> ootw_c16_end.inc
	$(PNG2RLE) asm another_pool.png pool_rle >> ootw_c16_end.inc


#####

clean:		
		rm -f *~ *.o *.lst *.lzz *.inc

