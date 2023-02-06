#include<stdio.h>
void main()
	
{
	/* this is program illustrates left shift operation
	 * a single left shift operation results in multiplication 
	 * of the original number*/
	unsigned char x = 0xF6;

	x = x << 2;

	printf("0x%X\n",x);

}
