#include<stdio.h>
void main()
{
	int x = 9;

	int *iptr = &x;

	printf("%d--------%p\n",*iptr, iptr);


	++*iptr;

	printf("%d--------%p\n",*iptr, iptr);
}

