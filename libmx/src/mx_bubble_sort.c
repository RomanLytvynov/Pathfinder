#include "../inc/libmx.h"

void mx_swap(char** s1, char** s2)
{
	char* temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int mx_bubble_sort(char**arr, int size)
{
	int counter = 0;

	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size-i-1; ++j)
		{
			if(mx_strcmp(arr[j], arr[j+1]) > 0) 
			{
				mx_swap(&arr[j], &arr[j+1]);
				counter++;
			}
		}
	}

	return counter;
}

