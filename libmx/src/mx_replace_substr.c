#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
	if(str == NULL || sub == NULL || replace == NULL) return NULL;

	int count_subs = mx_count_substr(str, sub);
	int new_size = mx_strlen(str) + (count_subs*mx_strlen(replace) - count_subs*mx_strlen(sub));
	char *rep = mx_strnew(new_size);

	if(mx_strlen(sub)==0) return (char*)str;
	else
	{
		int counter = 0;
		for (int i = 0, d_c = 0; i < mx_strlen(str); ++i, ++d_c)
		{
			if (str[i] == sub[0])
			{
				for (int j = i, k = 0; k < mx_strlen(sub); ++j, ++k)
				{
					if(str[j]!=sub[k]) break;
					else counter++;
				}
				if (counter == mx_strlen(sub)) 
				{
					for (int d = 0; d < mx_strlen(replace); ++d)
					{
						rep[d_c] = replace[d];
						d_c++;
					}
					i+=mx_strlen(sub)-1;
					d_c--;
					counter = 0;
					continue;
				}
			}
			counter = 0;
			rep[d_c] = str[i];
		}
	}
	return rep;
}

