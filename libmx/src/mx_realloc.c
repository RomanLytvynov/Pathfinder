#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size)
{
	size_t ptr_size;
	void* exit_obj;

	if(ptr == NULL)
		return malloc(size);
	ptr_size = malloc_size(ptr);

	if(size < ptr_size) return ptr;
	exit_obj = malloc(size);
	mx_memcpy(exit_obj, ptr, ptr_size);
	free(ptr);
	return exit_obj;
}

