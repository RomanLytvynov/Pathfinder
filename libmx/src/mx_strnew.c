#include "../inc/libmx.h"

char *mx_strnew(const int size)
{
	char*s = (char*)malloc((size+1) * sizeof(char));
	if(size < 0) return NULL;
	else
	{
		for (int i = 0; i < size+1; ++i)
		{
			s[i] = '\0';
		}
	}
	return s;
}

