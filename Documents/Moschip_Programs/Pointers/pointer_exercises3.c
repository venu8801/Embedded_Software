#include<stdio.h>
void main()
{
	int x = 8;

	int *iptr = &x;

	
	printf("%d--------%p\n",*iptr, iptr);


	++(*iptr);


	printf("%d--------%p\n",*iptr, iptr);

	++*(iptr);

	printf("%d--------%p\n",*iptr, iptr);

}
