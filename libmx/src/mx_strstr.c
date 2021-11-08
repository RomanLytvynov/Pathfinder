#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle)
{
	char *myhaystack = (char*)haystack;
	char *myneedle = (char*)needle;

	if(mx_strlen(myneedle)==0) return myhaystack;
	else
	{
		int counter = 0;
		for (int i = 0; i < mx_strlen(myhaystack); ++i)
		{
			if (myhaystack[i] == myneedle[0])
			{
				for (int j = i, k = 0; k < mx_strlen(myneedle); ++j, ++k)
				{
					if(myhaystack[j]!=myneedle[k]) break;
					else counter++;
				}
				if (counter == mx_strlen(myneedle)) return &myhaystack[i];
				else continue;
			}
			counter = 0;
		}
	}
	return NULL;
}

