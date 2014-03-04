/*
 * cutbits.c
 *
 *  Created on: 2014年3月4日
 *      Author: wkr@wangkerui.com
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

//#define __24_160__    "[LEN_24]"
#define __23_224__    "[LEN_23]"

#ifdef __24_160__
#define MASK 0x00ffffff
#define MASK_SZ 24
#endif

#ifdef __23_224__
#define MASK 0x007fffff
#define MASK_SZ 23
#endif

#define RAW_OFF 2

/*
 * 十六进制字符转换成整数；非法字符，返回-1
 * */
int
hexc2int(char c)
{
	switch(c)
	{
	case '1': case '2': case '3': case '4': case '5':
	case '6': case '7': case '8': case '9': case '0':
		return c - '0';
	case 'a': case 'A':
		return 10;
	case 'b': case 'B':
		return 11;
	case 'c': case 'C':
		return 12;
	case 'd': case 'D':
		return 13;
	case 'e': case 'E':
		return 14;
	case 'f': case 'F':
		return 15;
	default:
		return -1;
	}
}

void
cut_bits(char *raw, size_t sz)
{
	size_t raw_p = sz;
	uint32_t buffer = 0x0;
	size_t buffer_p = 0;

	printf("{");
	while ( raw_p > RAW_OFF )
	{
		while ( buffer_p < MASK_SZ && raw_p > RAW_OFF )
		{
			int tmp = hexc2int(raw[--raw_p]);
			buffer = buffer | (tmp << buffer_p);
			buffer_p += 4;
		}
		uint32_t tmp = buffer;
		tmp = tmp & MASK;
		printf("0x%x", tmp);
		if (raw_p > RAW_OFF) printf(", ");
		// reset
		buffer = buffer >> MASK_SZ;
		buffer_p = buffer_p - MASK_SZ;
	}
	printf("}");
	return;
}

void
cut_bits2(char* raw)
{
	size_t sz = strlen(raw);
	cut_bits(raw, sz);
}

void
format1()
{
	int idx = 0;
	char* prefix = "UINT32 PreP";
	char* fix = (char*)malloc(sizeof(char)*2);
	char* postfix = __23_224__;
	char* raw = (char*)malloc(sizeof(char)*60);
	while (EOF != scanf("%d\n", &idx))
	{
		scanf("%s", fix);
		printf("%s%d_%s%s = ", prefix, idx, fix, postfix);
		scanf("%s", raw);
		cut_bits2(raw);
		printf(";\n");

		scanf("%s", fix);
		printf("%s%d_%s%s = ", prefix, idx, fix, postfix);
		scanf("%s", raw);
		cut_bits2(raw);
		printf(";\n");

		scanf("%s", fix);
		printf("%s%d_%s%s = ", prefix, idx, fix, postfix);
		scanf("%s", raw);
		cut_bits2(raw);
		printf(";\n");

		printf("\n");
	}
	free(raw);
	free(fix);
}

void
format2()
{
	int idx = 0;
	printf("__constant__ ECPOINT table[256] = {\n\n");
	char* raw = (char*)malloc(sizeof(char)*60);
	char* fix = (char*)malloc(sizeof(char)*2);
	while (EOF != scanf("%d\n", &idx))
	{
		printf("{\n");

		scanf("%s", fix);
		scanf("%s", raw);
		cut_bits2(raw);
		printf(", \n");

		scanf("%s", fix);
		scanf("%s", raw);
		cut_bits2(raw);
		printf(", \n");

		scanf("%s", fix);
		scanf("%s", raw);
		cut_bits2(raw);
		printf("\n");

		printf("}, \n\n");
	}
	printf("};");
	free(fix);
	free(raw);
}
