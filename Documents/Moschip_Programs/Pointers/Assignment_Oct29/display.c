#include<stdio.h>
void display(int *ptr, int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		printf("%p------------%d\n",&ptr[i], ptr[i] );

	}
}
