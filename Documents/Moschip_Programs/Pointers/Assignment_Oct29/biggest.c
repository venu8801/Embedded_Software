#include<stdio.h>
int biggest(int *ptr, int n)
{
	int i,j;
	 
	
	int max = 0;
	for(i = 0; i < n; i++)
	{
		if(ptr[i] > max)
		{
			max = ptr[i];

		}
	}
	return max;
}	
		
