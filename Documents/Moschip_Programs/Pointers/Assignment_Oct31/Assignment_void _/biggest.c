#include<stdio.h>
int biggest(void *ptr, int n)
{
	int i,j;
	 
	
	int max = 0;
	for(i = 0; i < n; i++)
	{
		if(((int *)ptr)[i] > max)
		{
			max = ((int *)ptr)[i];

		}
	}
	return max;
}	
		
