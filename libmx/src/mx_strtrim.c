#include "../inc/libmx.h"

char *mx_strtrim(const char *str)
{
	if (str == NULL){
        return NULL;
    }

	int length = 0;
	char *on_exit = NULL;
	while(mx_isspace(*str)) 
	{
		str++;
	}
	length = mx_strlen(str);
	while (mx_isspace(str[length-1]))
	{
		length--;
	}
	on_exit = mx_strndup(str, length);
	return on_exit;

}

