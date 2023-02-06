// this is a program to clear a particular bit 
#include<stdio.h>
void main()
{
	unsigned int x;
	unsigned short int bit;
	
	printf("Enter the number:");

	scanf("%x",&x);

	printf("Enter the bit number to clear:");

	scanf("%hu",&bit);

	x = (x & ~(0x1 << bit));

	printf("The bit is cleared, after clearing the bit, value of x: %x\n",x);
}


