#include<stdio.h>
void main()
{
	// toggling a particluar bit
	unsigned char x = 0xff;

	// toggling bit 5
	x = x ^ 0x20;

	printf("0x%x\n",x);

}
