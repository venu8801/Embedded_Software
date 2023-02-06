#include<stdio.h>
void main()
{
	unsigned int x,y,z;

	x = y = z = 0xFFFF;

	x = ( x >> 5) << 5;

	y = ( y >> 3) << 3;
	
	z = (z >> 2) << 2;

	printf(" %x  %x  %x\n",x,y,z);
}
