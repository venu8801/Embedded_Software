#include<stdio.h>
void display(void *ptr, int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		printf("%p------------%d\n",&((int *)ptr)[i], ((int*)ptr)[i] );

	}
}
