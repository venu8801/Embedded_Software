#include<stdio.h>
void main()
{
	unsigned int x;


	printf("enter a number: ");

	scanf("%x",&x);


	//step 1 clear bits to be swapped
	//step 2 check status of those bits and shift them to their according places
	//perform bitwise or operation between step 1 and step 2


	x  = ( ( x & ~((0x1 << 0) | (0x1 << 31)) ) | ( ( x & (0x1 << 0) ) << 31)  | ( ( x & (0x1 << 31)) >> 31) );

	printf("swapped lsb with msb %x\n",x);
}	
