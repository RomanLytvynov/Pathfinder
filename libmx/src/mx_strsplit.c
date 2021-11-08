#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c)
{
    if(s == NULL || mx_strlen(s) > 512) 
    {
        return NULL;
    }
    int count = mx_count_words(s, c);
	char **str = (char**)malloc(count*sizeof(char*) + 1);
    for(int i = 0; i < count; i++)
    {
        str[i] = mx_strnew(512);
    }
    str[count] = NULL;
    char* s1 = mx_strtrim(s);
    for(int i = 0; i < count; i++)
    {
        char *str_word = mx_strnew(512);
        int j = 0;
		while(*s1 && *s1 == c)
        {
            s1++;
        }
        while(*s1 && *s1!=c)
        {
            str_word[j] = *s1;
            s1++;
            j++;
        }
        str[i] = mx_strcpy(str[i], str_word);
		free(str_word);
    }
	return str;
}


