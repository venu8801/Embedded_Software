#include<stdio.h>
void read(void *ptr, int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		scanf("%d",(( (int *)ptr ) + i));
	}
}
