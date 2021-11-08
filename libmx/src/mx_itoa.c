#include "../inc/libmx.h"

static int num_count(int n)
{
	int kol = 0;
    if (n/10==0)
      return 1;
   	else
    {
        while (n>0) 
        {
        	n=n/10;
        	kol+=1;
        }
        return kol;
    }     
 
}

char *mx_itoa(int number)
{	
	char *str = NULL;

	if(number == -2147483648)
	{
		str = mx_itoa(-2147483647);
		*(str+10) = '8';
	}
	else
	{
		if(number < 0)
		{
			number*=-1;
			int num_of = num_count(number);
			str = mx_strnew(num_of + 1);
			str[0] = '-';
			for (int i = num_of; i > 0; i--)//6
			{
				str[i] = (char)(((number%10)+48));
				number/=10;
			}
		}
		else
		{
			int num_of = num_count(number);
			str = mx_strnew(num_of);
			for (int i = num_of-1; i >= 0; i--)//6
			{
				str[i] = (char)(((number%10)+48));
				number/=10;
			}
		}
	}

	return str;
}

