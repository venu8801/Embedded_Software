#include<stdio.h>
void main()
{
	int a, b,c;

	a = 10, b = 10;

	c = a & b;

	if( (c ^ a) | (c ^ b))
	{
		printf("not equal");
	}
	else
		printf("equal\n");

	
}
