#include<stdio.h>
void Ascending_Order(void *ptr, int n)
{
	int i = 0, j = 0;


	for(i = 0; i < n;i++)
	{
		for(j = i + 1; j < n;j++)
		{
			if( *((int *)ptr+i) > *((int *)ptr + j) )
			{
				*((int *)ptr + i) = *((int *)ptr + i) ^ *((int *)ptr + j);
				*((int *)ptr + j) = *((int *)ptr + i) ^ *((int *)ptr + j);
				*((int *)ptr + i) = *((int *)ptr + i) ^ *((int *)ptr + j);
			}
		}	
		printf("%d\n",((int *)ptr)[i]);


	}
}
