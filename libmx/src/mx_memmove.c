#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *on_exit = (unsigned char *)dst;
	unsigned char *to_copy = (unsigned char *)src;
	char buff[len];
    for(size_t i = 0; i < len; i++)
    {
        buff[i] = to_copy[i];
    }
	for(size_t i = 0; i < len; i++)
    {
        on_exit[i] = buff[i];
    }
	return on_exit;
}

