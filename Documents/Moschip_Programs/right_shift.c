#include<stdio.h>
void main()
{
	int x = 0x80000000;

	x = x >> 16;

	printf("%x\n",x);
}

