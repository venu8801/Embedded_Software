#include<stdio.h>
void main()
{
	// this program is used to read byte by byte value from a 4 byte data
	unsigned int x;


	printf("Enter the 4 byte data:");

	scanf("%x",&x);

	unsigned char y = x;

	printf("first byte: %x\n",y);
	y = x >> 8;

	printf("second byte: %x\n",y);
	y = x >> 16;
	
	printf("third byte: %x\n",y);
	y = x >> 24;
	
	printf("fourth byte: %x\n",y);
}

	
