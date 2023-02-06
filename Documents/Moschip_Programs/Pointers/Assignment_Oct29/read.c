#include<stdio.h>
void read(int *ptr, int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		scanf("%d",(ptr + i));
	}
}
