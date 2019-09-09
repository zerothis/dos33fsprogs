#include <stdio.h>
#include <string.h>

// 8*12
static unsigned short PT3NoteTable_ST[]={
  0x0EF8,0x0E10,0x0D60,0x0C80,0x0BD8,0x0B28,0x0A88,0x09F0,  // 50
  0x0960,0x08E0,0x0858,0x07E0,0x077C,0x0708,0x06B0,0x0640,  // 58
  0x05EC,0x0594,0x0544,0x04F8,0x04B0,0x0470,0x042C,0x03FD,  // 60
  0x03BE,0x0384,0x0358,0x0320,0x02F6,0x02CA,0x02A2,0x027C,  // 68
  0x0258,0x0238,0x0216,0x01F8,0x01DF,0x01C2,0x01AC,0x0190,  // 70
  0x017B,0x0165,0x0151,0x013E,0x012C,0x011C,0x010A,0x00FC,  // 78
  0x00EF,0x00E1,0x00D6,0x00C8,0x00BD,0x00B2,0x00A8,0x009F,  // 80
  0x0096,0x008E,0x0085,0x007E,0x0077,0x0070,0x006B,0x0064,  // 88 (g#5-D#6)
  0x005E,0x0059,0x0054,0x004F,0x004B,0x0047,0x0042,0x003F,  // 90 (e6-b6)
  0x003B,0x0038,0x0035,0x0032,0x002F,0x002C,0x002A,0x0027,  // 98 (c7-g7)
  0x0025,0x0023,0x0021,0x001F,0x001D,0x001C,0x001A,0x0019,  // a0 (G#7-d#8)
  0x0017,0x0016,0x0015,0x0013,0x0012,0x0011,0x0010,0x000F   // a8 (e8-b8)
};

/* Table #2 of Pro Tracker 3.4x - 3.5x */
static unsigned short PT3NoteTable_ASM_34_35[] = {
0x0D10,0x0C55,0x0BA4,0x0AFC,0x0A5F,0x09CA,0x093D,0x08B8,0x083B,0x07C5,0x0755,0x06EC,
0x0688,0x062A,0x05D2,0x057E,0x052F,0x04E5,0x049E,0x045C,0x041D,0x03E2,0x03AB,0x0376,
0x0344,0x0315,0x02E9,0x02BF,0x0298,0x0272,0x024F,0x022E,0x020F,0x01F1,0x01D5,0x01BB,
0x01A2,0x018B,0x0174,0x0160,0x014C,0x0139,0x0128,0x0117,0x0107,0x00F9,0x00EB,0x00DD,
0x00D1,0x00C5,0x00BA,0x00B0,0x00A6,0x009D,0x0094,0x008C,0x0084,0x007C,0x0075,0x006F,
0x0069,0x0063,0x005D,0x0058,0x0053,0x004E,0x004A,0x0046,0x0042,0x003E,0x003B,0x0037,
0x0034,0x0031,0x002F,0x002C,0x0029,0x0027,0x0025,0x0023,0x0021,0x001F,0x001D,0x001C,
0x001A,0x0019,0x0017,0x0016,0x0015,0x0014,0x0012,0x0011,0x0010,0x000F,0x000E,0x000D,
};

/* Table #3 of Pro Tracker 3.4r */
static unsigned short PT3NoteTable_REAL_34r[] = {
  0x0CDA,0x0C22,0x0B73,0x0ACF,0x0A33,0x09A1,0x0917,0x0894,
  0x0819,0x07A4,0x0737,0x06CF,0x066D,0x0611,0x05BA,0x0567,
  0x051A,0x04D0,0x048B,0x044A,0x040C,0x03D2,0x039B,0x0367,
  0x0337,0x0308,0x02DD,0x02B4,0x028D,0x0268,0x0246,0x0225,
  0x0206,0x01E9,0x01CE,0x01B4,0x019B,0x0184,0x016E,0x015A,
  0x0146,0x0134,0x0123,0x0113,0x0103,0x00F5,0x00E7,0x00DA,
  0x00CE,0x00C2,0x00B7,0x00AD,0x00A3,0x009A,0x0091,0x0089,
  0x0082,0x007A,0x0073,0x006D,0x0067,0x0061,0x005C,0x0056,
  0x0052,0x004D,0x0049,0x0045,0x0041,0x003D,0x003A,0x0036,
  0x0033,0x0031,0x002E,0x002B,0x0029,0x0027,0x0024,0x0022,
  0x0020,0x001F,0x001D,0x001B,0x001A,0x0018,0x0017,0x0016,
  0x0014,0x0013,0x0012,0x0011,0x0010,0x000F,0x000E,0x000D,
};

#if 0


nt_data:
	DB (T_NEW_0-T1_)*2
	DB TCNEW_0-T_
	DB (T_OLD_0-T1_)*2+1
	DB TCOLD_0-T_
	DB (T_NEW_1-T1_)*2+1
	DB TCNEW_1-T_
	DB (T_OLD_1-T1_)*2+1
	DB TCOLD_1-T_
	DB (T_NEW_2-T1_)*2
	DB TCNEW_2-T_
	DB (T_OLD_2-T1_)*2
	DB TCOLD_2-T_
	DB (T_NEW_3-T1_)*2
	DB TCNEW_3-T_
	DB (T_OLD_3-T1_)*2
	DB TCOLD_3-T_

T_

TCOLD_0	DB #00+1,#04+1,#08+1,#0A+1,#0C+1,#0E+1,#12+1,#14+1
	DB #18+1,#24+1,#3C+1,0
TCOLD_1	DB #5C+1,0
TCOLD_2	DB #30+1,#36+1,#4C+1,#52+1,#5E+1,#70+1,#82,#8C,#9C
	DB #9E,#A0,#A6,#A8,#AA,#AC,#AE,#AE,0
TCNEW_3	DB #56+1
TCOLD_3	DB #1E+1,#22+1,#24+1,#28+1,#2C+1,#2E+1,#32+1,#BE+1,0
TCNEW_0	DB #1C+1,#20+1,#22+1,#26+1,#2A+1,#2C+1,#30+1,#54+1
	DB #BC+1,#BE+1,0
TCNEW_1 EQU TCOLD_1
TCNEW_2	DB #1A+1,#20+1,#24+1,#28+1,#2A+1,#3A+1,#4C+1,#5E+1
	DB #BA+1,#BC+1,#BE+1,0

#endif

/* first 12 values of tone tables (packed) */
static unsigned char t_pack[]={
  0x06EC*2/256,0x06EC*2,
  0x0755-0x06EC,
  0x07C5-0x0755,
  0x083B-0x07C5,
  0x08B8-0x083B,
  0x093D-0x08B8,
  0x09CA-0x093D,
  0x0A5F-0x09CA,
  0x0AFC-0x0A5F,
  0x0BA4-0x0AFC,
  0x0C55-0x0BA4,
  0x0D10-0x0C55,
  0x066D*2/256,0x066D*2,
  0x06CF-0x066D,
  0x0737-0x06CF,
  0x07A4-0x0737,
  0x0819-0x07A4,
  0x0894-0x0819,
  0x0917-0x0894,
  0x09A1-0x0917,
  0x0A33-0x09A1,
  0x0ACF-0x0A33,
  0x0B73-0x0ACF,
  0x0C22-0x0B73,
  0x0CDA-0x0C22,
  0x0704*2/256,0x0704*2,
  0x076E - 0x0704,
  0x07E0-0x076E,
  0x0858-0x07E0,
  0x08D6-0x0858,
  0x095C-0x08D6,
  0x09EC-0x095C,
  0x0A82-0x09EC,
  0x0B22-0x0A82,
  0x0BCC-0x0B22,
  0x0C80-0x0BCC,
  0x0d3e - 0x0c80,
  0x07E0*2/256,0x07E0*2,
  0x0858-0x07E0,
  0x08E0-0x0858,
  0x0960-0x08E0,
  0x09F0-0x0960,
  0x0A88-0x09F0,
  0x0B28-0x0A88,
  0x0BD8-0x0B28,
  0x0C80-0x0BD8,
  0x0D60-0x0C80,
  0x0E10-0x0D60,
  0x0EF8-0x0E10,
};

static unsigned short Tone[256];


// NoteTableCreator (c) Ivan Roshin
// A - NoteTableNumber*2+VersionForNoteTable
// (xx1b - 3.xx..3.4r, xx0b - 3.4x..3.6x..VTII1.0)

void NoteTableCreator(int which) {

	unsigned short hl,de;
	unsigned char a,b,c,carry,old_carry;
	unsigned short ix;
	unsigned short s[16];
	unsigned int temp1,temp2;
	int self_modified=0;
	int sp=0;

//LD HL,NT_DATA
	s[0]=de;	// PUSH DE
	sp++;

	de=de&0x00ff;
	de|=b<<8;	//LD D,B

	if (a&0x80) carry=1;
	else carry=0;
	a=a+a;		//ADD A,A


	de=de&0xff00;
	de|=a;		//LD E,A

	hl=hl+de;	//ADD HL,DE

//LD E,(HL)
	hl++;		// INC HL
//SRL E
//SBC A,A
//AND #A7 ;#00 (NOP) or #A7 (AND A)
//LD (L3),A
//EX DE,HL
//POP BC ;BC=T1_
//ADD HL,BC

//LD A,(DE)
//ADD A,T_
	c=a;		// LD C,A
//ADC A,T_/256
//SUB C
	b=a;		// LD B,A
//PUSH BC
//LD DE,NT_
//PUSH DE

	b=12;		// LD B,12
L1:
//PUSH BC
//LD C,(HL)
//INC HL
//PUSH HL
//LD B,(HL)

//PUSH DE
//EX DE,HL
//LD DE,23
//LD IXH,8
L2:
//SRL B
//RR C
L3:
//DB #19  ;AND A or NOP
	a=c;		// LD A,C
//ADC A,D ;=ADC 0
//LD (HL),A
	hl++;		// INC HL
//LD A,B
//ADC A,D
//LD (HL),A
//ADD HL,DE
//DEC IXH
//JR NZ,L2

//POP DE
	de++;		// INC DE
	de++;		// INC DE
//POP HL
	hl++;		// INC HL
//POP BC
//DJNZ L1
//POP HL
//POP DE

	a=(de&0xff);	// LD A,E
//CP TCOLD_1
//JR NZ,CORR_1
//LD A,#FD
//LD (NT_+#2E),A
CORR_1:
//LD A,(DE)
//AND A
	if (a==0) goto TC_EXIT;		// JR Z,TC_EXIT
//RRA
//PUSH AF
//ADD A,A
	c=a;	// LD C,A
//ADD HL,BC
//POP AF
	if (carry==0) goto CORR_2;	// JR NC,CORR_2
//DEC (HL)
//DEC (HL)
CORR_2:
//INC (HL)
//AND A
//SBC HL,BC
	de++;		//INC DE
	goto CORR_1;	// JR CORR_1

TC_EXIT:

	sp--;
	a=(s[sp]>>8); //POP AF



}


int main(int argc, char **argv) {

	int i;

	NoteTableCreator(0);

	for(i=0;i<8*12;i++) {
		if (i%12==0) printf("\n");
		printf(" %04X",Tone[i]);
	}
	printf("\n");

	if (!memcmp(Tone,PT3NoteTable_ST,8*12*sizeof(short))) {
		printf("MATCH 35\n");
	}
	else {
		printf("NO MATCH 35\n");
	}

	if (!memcmp(Tone,PT3NoteTable_ASM_34_35,8*12*sizeof(short))) {
		printf("MATCH 34\n");
	}
	else {
		printf("NO MATCH 34\n");
	}




	NoteTableCreator(1);

	for(i=0;i<8*12;i++) {
		if (i%12==0) printf("\n");
		printf(" %04X",Tone[i]);
	}
	printf("\n");

	if (!memcmp(Tone,PT3NoteTable_ST,8*12*sizeof(short))) {
		printf("MATCH 35\n");
	}
	else {
		printf("NO MATCH 35\n");
	}

	if (!memcmp(Tone,PT3NoteTable_ASM_34_35,8*12*sizeof(short))) {
		printf("MATCH 34\n");
	}
	else {
		printf("NO MATCH 34\n");
	}



}



