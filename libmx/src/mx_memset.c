#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len)
{
	unsigned char *on_exit = (unsigned char*)b;
	for (size_t i = 0; i < len; ++i)
	{
		on_exit[i] = (unsigned char)c;
	}
	return on_exit;
}

