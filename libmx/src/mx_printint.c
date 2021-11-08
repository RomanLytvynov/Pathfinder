#include "../inc/libmx.h"

int mx_count(int n)
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

void mx_printint(int n)
{
  if(n < 0 && n!=-2147483648)
  {
    n*=-1;
    int size = mx_count(n);
    char result[size+1];
    for(int i = 0; i < size+1; ++i)
    {
      if (i == size)
      {
        result[0] = '-';
        break;
      }
      result[size-i] = (char)((n % 10)+48);
      n /= 10; 
    }

    for (int i = 0; i < size+1; ++i)
    {
      mx_printchar(result[i]);
    }
  }
  else if (n == -2147483648)
  {
    mx_printchar('-');
    mx_printint(214748364);
    mx_printint(8);
  }
  else
  {
    int size = mx_count(n);
    char result[size];
    for(int i=0; i<size; ++i)
    {
      result[size-1-i] = (char)((n % 10)+48);
      n /= 10; 
    }
    for (int i = 0; i < size; ++i)
    {
      mx_printchar(result[i]);
    }
  }
}

