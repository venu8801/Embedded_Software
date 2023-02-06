#include<stdio.h>
void main()
{
	char x = 0x80;

	printf("%x\n",x);

	printf("%x\n", (x & ~(0xf << 0)) );
}

