#include "../inc/libmx.h"

int mx_count_substr(const char*str, const char*sub)
{
	if(str == NULL || sub == NULL) return -1;
	char *myhaystack = (char*)str;
	char *myneedle = (char*)sub;
	int counter_chars = 0, counter = 0;

	if(mx_strlen(myneedle)==0) return 0;
	else
	{
		for (int i = 0; i < mx_strlen(myhaystack); ++i)
		{
			if (myhaystack[i] == myneedle[0])
			{
				for (int j = i, k = 0; k < mx_strlen(myneedle); ++j, ++k)
				{
					if(myhaystack[j]!=myneedle[k]) break;
					else counter_chars++;
				}
				if (counter_chars == mx_strlen(myneedle)) counter++;
				else continue;
			}
			counter_chars = 0;
		}
	}
	return counter;
}

