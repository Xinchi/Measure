#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <malloc.h>
#include <memory.h>
#include "bw.h"

//#define write 1
#define read 1
#define long_step 1
//#define int_step 1
//#define char_step 1
#define chunk 256
unsigned long get_tsc(void)
{
    register unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long)hi << 32UL) | (unsigned long)lo;
}

int write_m(char* src ,int size)
{
    unsigned long i;
#ifdef int_step
    for (i = 0; i < size; i+=chunk)
    {
	((int*)src)[0] = 0;  ((int*)src)[1] = 0;  ((int*)src)[2] = 0;  ((int*)src)[3] = 0;  ((int*)src)[4] = 0;  ((int*)src)[5] = 0;  ((int*)src)[6] = 0;  ((int*)src)[7] = 0;  ((int*)src)[8] = 0;  ((int*)src)[9] = 0;  ((int*)src)[10] = 0;  ((int*)src)[11] = 0;  ((int*)src)[12] = 0;  ((int*)src)[13] = 0;  ((int*)src)[14] = 0;  ((int*)src)[15] = 0;  ((int*)src)[16] = 0;  ((int*)src)[17] = 0;  ((int*)src)[18] = 0;  ((int*)src)[19] = 0;  ((int*)src)[20] = 0;  ((int*)src)[21] = 0;  ((int*)src)[22] = 0;  ((int*)src)[23] = 0;  ((int*)src)[24] = 0;  ((int*)src)[25] = 0;  ((int*)src)[26] = 0;  ((int*)src)[27] = 0;  ((int*)src)[28] = 0;  ((int*)src)[29] = 0;  ((int*)src)[30] = 0;  ((int*)src)[31] = 0;  ((int*)src)[32] = 0;  ((int*)src)[33] = 0;  ((int*)src)[34] = 0;  ((int*)src)[35] = 0;  ((int*)src)[36] = 0;  ((int*)src)[37] = 0;  ((int*)src)[38] = 0;  ((int*)src)[39] = 0;  ((int*)src)[40] = 0;  ((int*)src)[41] = 0;  ((int*)src)[42] = 0;  ((int*)src)[43] = 0;  ((int*)src)[44] = 0;  ((int*)src)[45] = 0;  ((int*)src)[46] = 0;  ((int*)src)[47] = 0;  ((int*)src)[48] = 0;  ((int*)src)[49] = 0;  ((int*)src)[50] = 0;  ((int*)src)[51] = 0;  ((int*)src)[52] = 0;  ((int*)src)[53] = 0;  ((int*)src)[54] = 0;  ((int*)src)[55] = 0;  ((int*)src)[56] = 0;  ((int*)src)[57] = 0;  ((int*)src)[58] = 0;  ((int*)src)[59] = 0;  ((int*)src)[60] = 0;  ((int*)src)[61] = 0;  ((int*)src)[62] = 0;  ((int*)src)[63] = 0; 
	src = src + chunk;
    }
#endif
#ifdef long_step
    for (i = 0; i < (size); i+=chunk)
    {
	((long*)src)[0] = 0;  ((long*)src)[1] = 0;  ((long*)src)[2] = 0;  ((long*)src)[3] = 0;  ((long*)src)[4] = 0;  ((long*)src)[5] = 0;  ((long*)src)[6] = 0;  ((long*)src)[7] = 0;  ((long*)src)[8] = 0;  ((long*)src)[9] = 0;  ((long*)src)[10] = 0;  ((long*)src)[11] = 0;  ((long*)src)[12] = 0;  ((long*)src)[13] = 0;  ((long*)src)[14] = 0;  ((long*)src)[15] = 0;  ((long*)src)[16] = 0;  ((long*)src)[17] = 0;  ((long*)src)[18] = 0;  ((long*)src)[19] = 0;  ((long*)src)[20] = 0;  ((long*)src)[21] = 0;  ((long*)src)[22] = 0;  ((long*)src)[23] = 0;  ((long*)src)[24] = 0;  ((long*)src)[25] = 0;  ((long*)src)[26] = 0;  ((long*)src)[27] = 0;  ((long*)src)[28] = 0;  ((long*)src)[29] = 0;  ((long*)src)[30] = 0;  ((long*)src)[31] = 0; 
	src = src + chunk;
    }
#endif
#ifdef char_step
    for (i = 0; i < (size); i+= chunk)
    {
	src[0] = 0;  src[1] = 0;  src[2] = 0;  src[3] = 0;  src[4] = 0;  src[5] = 0;  src[6] = 0;  src[7] = 0;  src[8] = 0;  src[9] = 0;  src[10] = 0;  src[11] = 0;  src[12] = 0;  src[13] = 0;  src[14] = 0;  src[15] = 0;  src[16] = 0;  src[17] = 0;  src[18] = 0;  src[19] = 0;  src[20] = 0;  src[21] = 0;  src[22] = 0;  src[23] = 0;  src[24] = 0;  src[25] = 0;  src[26] = 0;  src[27] = 0;  src[28] = 0;  src[29] = 0;  src[30] = 0;  src[31] = 0;  src[32] = 0;  src[33] = 0;  src[34] = 0;  src[35] = 0;  src[36] = 0;  src[37] = 0;  src[38] = 0;  src[39] = 0;  src[40] = 0;  src[41] = 0;  src[42] = 0;  src[43] = 0;  src[44] = 0;  src[45] = 0;  src[46] = 0;  src[47] = 0;  src[48] = 0;  src[49] = 0;  src[50] = 0;  src[51] = 0;  src[52] = 0;  src[53] = 0;  src[54] = 0;  src[55] = 0;  src[56] = 0;  src[57] = 0;  src[58] = 0;  src[59] = 0;  src[60] = 0;  src[61] = 0;  src[62] = 0;  src[63] = 0;  src[64] = 0;  src[65] = 0;  src[66] = 0;  src[67] = 0;  src[68] = 0;  src[69] = 0;  src[70] = 0;  src[71] = 0;  src[72] = 0;  src[73] = 0;  src[74] = 0;  src[75] = 0;  src[76] = 0;  src[77] = 0;  src[78] = 0;  src[79] = 0;  src[80] = 0;  src[81] = 0;  src[82] = 0;  src[83] = 0;  src[84] = 0;  src[85] = 0;  src[86] = 0;  src[87] = 0;  src[88] = 0;  src[89] = 0;  src[90] = 0;  src[91] = 0;  src[92] = 0;  src[93] = 0;  src[94] = 0;  src[95] = 0;  src[96] = 0;  src[97] = 0;  src[98] = 0;  src[99] = 0;  src[100] = 0;  src[101] = 0;  src[102] = 0;  src[103] = 0;  src[104] = 0;  src[105] = 0;  src[106] = 0;  src[107] = 0;  src[108] = 0;  src[109] = 0;  src[110] = 0;  src[111] = 0;  src[112] = 0;  src[113] = 0;  src[114] = 0;  src[115] = 0;  src[116] = 0;  src[117] = 0;  src[118] = 0;  src[119] = 0;  src[120] = 0;  src[121] = 0;  src[122] = 0;  src[123] = 0;  src[124] = 0;  src[125] = 0;  src[126] = 0;  src[127] = 0;  src[128] = 0;  src[129] = 0;  src[130] = 0;  src[131] = 0;  src[132] = 0;  src[133] = 0;  src[134] = 0;  src[135] = 0;  src[136] = 0;  src[137] = 0;  src[138] = 0;  src[139] = 0;  src[140] = 0;  src[141] = 0;  src[142] = 0;  src[143] = 0;  src[144] = 0;  src[145] = 0;  src[146] = 0;  src[147] = 0;  src[148] = 0;  src[149] = 0;  src[150] = 0;  src[151] = 0;  src[152] = 0;  src[153] = 0;  src[154] = 0;  src[155] = 0;  src[156] = 0;  src[157] = 0;  src[158] = 0;  src[159] = 0;  src[160] = 0;  src[161] = 0;  src[162] = 0;  src[163] = 0;  src[164] = 0;  src[165] = 0;  src[166] = 0;  src[167] = 0;  src[168] = 0;  src[169] = 0;  src[170] = 0;  src[171] = 0;  src[172] = 0;  src[173] = 0;  src[174] = 0;  src[175] = 0;  src[176] = 0;  src[177] = 0;  src[178] = 0;  src[179] = 0;  src[180] = 0;  src[181] = 0;  src[182] = 0;  src[183] = 0;  src[184] = 0;  src[185] = 0;  src[186] = 0;  src[187] = 0;  src[188] = 0;  src[189] = 0;  src[190] = 0;  src[191] = 0;  src[192] = 0;  src[193] = 0;  src[194] = 0;  src[195] = 0;  src[196] = 0;  src[197] = 0;  src[198] = 0;  src[199] = 0;  src[200] = 0;  src[201] = 0;  src[202] = 0;  src[203] = 0;  src[204] = 0;  src[205] = 0;  src[206] = 0;  src[207] = 0;  src[208] = 0;  src[209] = 0;  src[210] = 0;  src[211] = 0;  src[212] = 0;  src[213] = 0;  src[214] = 0;  src[215] = 0;  src[216] = 0;  src[217] = 0;  src[218] = 0;  src[219] = 0;  src[220] = 0;  src[221] = 0;  src[222] = 0;  src[223] = 0;  src[224] = 0;  src[225] = 0;  src[226] = 0;  src[227] = 0;  src[228] = 0;  src[229] = 0;  src[230] = 0;  src[231] = 0;  src[232] = 0;  src[233] = 0;  src[234] = 0;  src[235] = 0;  src[236] = 0;  src[237] = 0;  src[238] = 0;  src[239] = 0;  src[240] = 0;  src[241] = 0;  src[242] = 0;  src[243] = 0;  src[244] = 0;  src[245] = 0;  src[246] = 0;  src[247] = 0;  src[248] = 0;  src[249] = 0;  src[250] = 0;  src[251] = 0;  src[252] = 0;  src[253] = 0;  src[254] = 0;  src[255] = 0; 
	src = src + chunk;
    }
#endif
    return 0;
}
int read_m(char* src,int size)
{
    unsigned long i;
    register long sum = 0;
#ifdef int_step 
    for (i = 0; i < size; i+=chunk)
    {
	sum = ((int*)src)[0] +  ((int*)src)[1] +  ((int*)src)[2] +  ((int*)src)[3] +  ((int*)src)[4] +  ((int*)src)[5] +  ((int*)src)[6] +  ((int*)src)[7] +  ((int*)src)[8] +  ((int*)src)[9] +  ((int*)src)[10] +  ((int*)src)[11] +  ((int*)src)[12] +  ((int*)src)[13] +  ((int*)src)[14] +  ((int*)src)[15] +  ((int*)src)[16] +  ((int*)src)[17] +  ((int*)src)[18] +  ((int*)src)[19] +  ((int*)src)[20] +  ((int*)src)[21] +  ((int*)src)[22] +  ((int*)src)[23] +  ((int*)src)[24] +  ((int*)src)[25] +  ((int*)src)[26] +  ((int*)src)[27] +  ((int*)src)[28] +  ((int*)src)[29] +  ((int*)src)[30] +  ((int*)src)[31] +  ((int*)src)[32] +  ((int*)src)[33] +  ((int*)src)[34] +  ((int*)src)[35] +  ((int*)src)[36] +  ((int*)src)[37] +  ((int*)src)[38] +  ((int*)src)[39] +  ((int*)src)[40] +  ((int*)src)[41] +  ((int*)src)[42] +  ((int*)src)[43] +  ((int*)src)[44] +  ((int*)src)[45] +  ((int*)src)[46] +  ((int*)src)[47] +  ((int*)src)[48] +  ((int*)src)[49] +  ((int*)src)[50] +  ((int*)src)[51] +  ((int*)src)[52] +  ((int*)src)[53] +  ((int*)src)[54] +  ((int*)src)[55] +  ((int*)src)[56] +  ((int*)src)[57] +  ((int*)src)[58] +  ((int*)src)[59] +  ((int*)src)[60] +  ((int*)src)[61] +  ((int*)src)[62] + ((int*)src)[63] ;
	src = src + chunk;
    }
    return sum;
#endif
#ifdef long_step
    for (i = 0; i < (size); i+=chunk)
    {
	sum = ((long*)src)[0] +  ((long*)src)[1] +  ((long*)src)[2] +  ((long*)src)[3] +  ((long*)src)[4] +  ((long*)src)[5] +  ((long*)src)[6] +  ((long*)src)[7] +  ((long*)src)[8] +  ((long*)src)[9] +  ((long*)src)[10] +  ((long*)src)[11] +  ((long*)src)[12] +  ((long*)src)[13] +  ((long*)src)[14] +  ((long*)src)[15] +  ((long*)src)[16] +  ((long*)src)[17] +  ((long*)src)[18] +  ((long*)src)[19] +  ((long*)src)[20] +  ((long*)src)[21] +  ((long*)src)[22] +  ((long*)src)[23] +  ((long*)src)[24] +  ((long*)src)[25] +  ((long*)src)[26] +  ((long*)src)[27] +  ((long*)src)[28] +  ((long*)src)[29] +  ((long*)src)[30] +  ((long*)src)[31] ;
	src = src + chunk;
    }
#endif
#ifdef char_step
    for (i = 0; i < (size); i+= chunk)
    {
	//fprintf(stderr, "addr=%lu\n", src);
	//fprintf(stderr, "done, %lu\n", i);
	sum = src[0] +  src[1] +  src[2] +  src[3] +  src[4] +  src[5] +  src[6] +  src[7] +  src[8] +  src[9] +  src[10] +  src[11] +  src[12] +  src[13] +  src[14] +  src[15] +  src[16] +  src[17] +  src[18] +  src[19] +  src[20] +  src[21] +  src[22] +  src[23] +  src[24] +  src[25] +  src[26] +  src[27] +  src[28] +  src[29] +  src[30] +  src[31] +  src[32] +  src[33] +  src[34] +  src[35] +  src[36] +  src[37] +  src[38] +  src[39] +  src[40] +  src[41] +  src[42] +  src[43] +  src[44] +  src[45] +  src[46] +  src[47] +  src[48] +  src[49] +  src[50] +  src[51] +  src[52] +  src[53] +  src[54] +  src[55] +  src[56] +  src[57] +  src[58] +  src[59] +  src[60] +  src[61] +  src[62] +  src[63] +  src[64] +  src[65] +  src[66] +  src[67] +  src[68] +  src[69] +  src[70] +  src[71] +  src[72] +  src[73] +  src[74] +  src[75] +  src[76] +  src[77] +  src[78] +  src[79] +  src[80] +  src[81] +  src[82] +  src[83] +  src[84] +  src[85] +  src[86] +  src[87] +  src[88] +  src[89] +  src[90] +  src[91] +  src[92] +  src[93] +  src[94] +  src[95] +  src[96] +  src[97] +  src[98] +  src[99] +  src[100] +  src[101] +  src[102] +  src[103] +  src[104] +  src[105] +  src[106] +  src[107] +  src[108] +  src[109] +  src[110] +  src[111] +  src[112] +  src[113] +  src[114] +  src[115] +  src[116] +  src[117] +  src[118] +  src[119] +  src[120] +  src[121] +  src[122] +  src[123] +  src[124] +  src[125] +  src[126] +  src[127] +  src[128] +  src[129] +  src[130] +  src[131] +  src[132] +  src[133] +  src[134] +  src[135] +  src[136] +  src[137] +  src[138] +  src[139] +  src[140] +  src[141] +  src[142] +  src[143] +  src[144] +  src[145] +  src[146] +  src[147] +  src[148] +  src[149] +  src[150] +  src[151] +  src[152] +  src[153] +  src[154] +  src[155] +  src[156] +  src[157] +  src[158] +  src[159] +  src[160] +  src[161] +  src[162] +  src[163] +  src[164] +  src[165] +  src[166] +  src[167] +  src[168] +  src[169] +  src[170] +  src[171] +  src[172] +  src[173] +  src[174] +  src[175] +  src[176] +  src[177] +  src[178] +  src[179] +  src[180] +  src[181] +  src[182] +  src[183] +  src[184] +  src[185] +  src[186] +  src[187] +  src[188] +  src[189] +  src[190] +  src[191] +  src[192] +  src[193] +  src[194] +  src[195] +  src[196] +  src[197] +  src[198] +  src[199] +  src[200] +  src[201] +  src[202] +  src[203] +  src[204] +  src[205] +  src[206] +  src[207] +  src[208] +  src[209] +  src[210] +  src[211] +  src[212] +  src[213] +  src[214] +  src[215] +  src[216] +  src[217] +  src[218] +  src[219] +  src[220] +  src[221] +  src[222] +  src[223] +  src[224] +  src[225] +  src[226] +  src[227] +  src[228] +  src[229] +  src[230] +  src[231] +  src[232] +  src[233] +  src[234] +  src[235] +  src[236] +  src[237] +  src[238] +  src[239] +  src[240] +  src[241] +  src[242] +  src[243] +  src[244] +  src[245] +  src[246] +  src[247] +  src[248] +  src[249] +  src[250] +  src[251] +  src[252] +  src[253] +  src[254] + src[255];
	src = src + chunk;
    }
#endif
    return sum;
}
int main(int argc, char** argv)
{
    struct timeval n1;
    unsigned long t1, t2;
    char* array;
    unsigned long size;
    struct timeval n2;
    if (argc > 1)
    {
	size = atoi(argv[1]);
    }else{
	size = 512 * 1024;
    }
    size = size * 1024;
    array = malloc(size);
    int i;
    for (i = 0; i < size; i++)
    {
	array[i] = 'a';
    }
    //fprintf(stderr, "%ld\n", size);
    //fprintf(stderr, "%lu\n", array);
    
    int run;
    unsigned long interval;
    double bandwidth;

    unsigned char cache[4 * 1024 * 1024];
    int sum;
    for (run = 0; run < 1000; run++)
    {
	for (i = 0; i < 10240; i++)
	{
	    cache[i] = 1;
	}
	t1 = get_tsc();
	#ifdef read
	    read_m(array, size);
	#endif
	#ifdef write
	    write_m(array, size);
	#endif
	//gettimeofday(&n2);
	t2 = get_tsc();

	interval = t2 - t1;
	bandwidth = size * 2530.0 / interval;
	printf("%f,\n", bandwidth);
    }

	/*
	interval = 0;

	interval = (unsigned long long)(n2.tv_sec - n1.tv_sec) * 1000000
		    + (n2.tv_usec - n1.tv_usec);
	fprintf(stderr,"%f\n", size * 1000000.0 / interval / 1024 / 1024);
	printf("%f\n", size * 1000000.0 / interval / 1024 / 1024);
   */
    return 0;
}
