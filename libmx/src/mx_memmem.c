#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
	unsigned char *str = NULL;
	unsigned char *substr = NULL;

	if (big_len >= little_len && big_len > 0 && little_len > 0) {
		str = (unsigned char *)big;
		substr = (unsigned char *)little;
		while (*str) {
			if (mx_memcmp(str, substr, little_len - 1) == 0)
				return str;
			str++;
		}
	}
	return NULL;
}

