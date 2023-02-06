#include<stdio.h>
void main()
{
	unsigned int x;

	printf("Enter 4 byte integer");

	scanf("%x",&x);

	printf("%x\n",(x & ~(0xffffff << 8)));

	x = x >> 8;

	printf("%x\n",(x&~(0xffff << 8)));

	x = x >> 8;

	printf("%x\n",(x&~(0xff << 8)));

	x = x >> 8;

	printf("%x\n",x);
}
