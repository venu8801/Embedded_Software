#include<stdio.h>
void main()
{
	// swapping of first and last byte
	unsigned int x;

	printf("Enter 4 byte integer");

	scanf("%x",&x);


	// first clear first byte and last byte	// check status of first byte and shift the byte to left
	x = ( ( x & ~((0xff << 0) | (0xff << 24)) ) | ((x & (0xff << 0)) << 24) | (( x & (0xff << 24)) >> 24));
	printf("after swapping first and last byte: %x\n",x);
}
