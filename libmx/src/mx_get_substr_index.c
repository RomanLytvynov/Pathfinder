#include "../inc/libmx.h"

int mx_get_substr_index(const char*str, const char*sub)
{
	if(str == NULL || sub == NULL) return -2;
	char *myhaystack = (char*)str;
	char *myneedle = (char*)sub;

	if(mx_strlen(myneedle)==0) return 0;
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
				if (counter == mx_strlen(myneedle)) return i;
				else continue;
			}
			counter = 0;
		}
	}
	return -1;
}

