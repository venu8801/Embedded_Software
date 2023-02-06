// this is a program to set a particular bit 
#include<stdio.h>
void main()
{
	unsigned int x;
	unsigned short int bit;
	
	printf("Enter the number:");

	scanf("%x",&x);

	printf("Enter the bit number to set:");

	scanf("%hu",&bit);

	x = (x | (0x1 << bit));

	printf("The bit is set, after setting the bit value of x: %x\n",x);
}


