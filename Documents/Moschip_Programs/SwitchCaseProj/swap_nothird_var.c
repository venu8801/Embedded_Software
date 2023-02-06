#include<stdio.h>
void swap_nothird_var(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	printf("After swapping x=%d and y=%d\n",a,b);
}
