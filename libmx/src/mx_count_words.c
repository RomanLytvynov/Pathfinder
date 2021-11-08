#include "../inc/libmx.h"

int mx_count_words(const char *str, char c)
{
	int counter = 0;
	int i = 0;

	if(c != ' ' && !mx_isalpha(c))
	{
		while(*(str + i)!= '\0')
		{
			if(mx_isalpha(str[i])||mx_isdigit(str[i]))
			{
				int j = i;
				while(true) 
				{
					if(str[j]==c) break;
				    if(str[j]=='\0') break;
				    j++;
				}
				i = j;
				counter++;
			}
			else
			i++;
		}
	}
	else
	{
		while(*(str + i)!= '\0')
		{
			if(str[i]!=c)
			{
				int j = i;
				while(true) 
				{
					if(str[j]==c) break;
				    if(str[j]=='\0') break;
				    j++;
				}
				i = j;
				counter++;
			}
			else i++;
		}
	}
	return counter;
}

