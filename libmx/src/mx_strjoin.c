#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2)
{
	if(s1 == NULL && s2 == NULL) return NULL;
	else if(s1 == NULL || s2 == NULL) 
	{
		if (s1 == NULL)
		{
			return mx_strdup(s2);
		}
		else
		{
			return mx_strdup(s1);
		}
	}
	else
	{
		int cat_size = mx_strlen(s1) + mx_strlen(s2);
		char*cat = mx_strnew(cat_size);
		cat = mx_strcpy(cat, s1);
		cat = mx_strcat(cat, s2);
		return cat; 
	}
}

