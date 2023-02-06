#include<stdio.h>
void swap_third_var(int a, int b)
{
	int c;

	c = a;

	a = b;

	b = c;

	printf("After swapping x=%d and y=%d\n",a,b);


}
