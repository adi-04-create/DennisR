#include <stdio.h>
#include <stdint.h>

struct header
{
	uint16_t chksum;
	uint16_t window;
	uint16_t source;
	uint16_t destin;
};


