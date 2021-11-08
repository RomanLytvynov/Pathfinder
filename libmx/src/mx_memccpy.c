#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
	unsigned char *on_exit = (unsigned char*)dst;
	unsigned char *source = (unsigned char*)src;

	for (size_t i = 0; i < n; ++i)
	{
		on_exit[i] = source[i];
		if(source[i] == (unsigned char)c) 
			return &(on_exit[i+1]);
	}
	return on_exit;
}

