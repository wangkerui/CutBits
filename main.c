/*
 * main.c
 *
 *  Created on: 2014年2月18日
 *      Author: wkr@wangkerui.com
 */
#include<stdio.h>
#include<unistd.h>

//#define __24__ 24
#define __23__ 23

#ifdef __24__
#define RAW_SZ 160
#define RAW_HEX_SZ RAW_SZ/4
#define MASK 0x00ffffff
#define MASK_SZ 24
#endif

#ifdef __23__
#define RAW_SZ 224
#define RAW_HEX_SZ RAW_SZ/4
#define MASK 0x007fffff
#define MASK_SZ 23
#endif

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
		return 0;
	}
}

int
main(int argc, char *args[])
{
	char *raw = args[1];
	//printf("%s\n\n", raw);
	size_t raw_p = RAW_HEX_SZ;
	uint32_t buffer = 0x0;
	size_t buffer_p = 0;

	while ( raw_p > 0 )
	{
		while ( buffer_p < MASK_SZ && raw_p > 0 )
		{
			int tmp = hexc2int(raw[--raw_p]);
			buffer = buffer | (tmp << buffer_p);
			buffer_p += 4;
		}
		uint32_t tmp = buffer;
		tmp = tmp & MASK;
		printf("%x\n", tmp);
		// reset
		buffer = buffer >> MASK_SZ;
		buffer_p = buffer_p - MASK_SZ;
	}

	return 0;
}

