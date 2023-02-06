#include<stdio.h>
void main()
{
	int x = 6;

	int *iptr = &x;

	
	printf("%d--------%p\n",*iptr, iptr);

	(*iptr)++;


	printf("%d--------%p\n",*iptr, iptr);
}
