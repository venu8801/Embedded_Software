#include<stdio.h>
#include<stdlib.h>
void main()
{
	unsigned int x;

	unsigned int temp,bit1,bit2;

	printf("Enter 4 byte integer value");

	scanf("%x",&x);

	printf("Enter bits to be swapped bit1 : bit2 -: ");
	
	scanf("%d:%d",&bit1,&bit2);

	( (bit1 >= 0) && (bit1 <= 31) ) ? 0: (printf("Invalid Inputs"),exit(0));
	( (bit2 >= 0) && (bit2 <= 31) ) ? 0: (printf("Invalid Inputs"),exit(0));

	bit1 > bit2 ? ( temp = bit1, bit1 = bit2, bit2 = temp) : 0;

x = ( (x & ~( (0x1 << bit1)|(0x1 << bit2) ) )  |  ((x & (0x1 << bit1)) << (bit2 - bit1)) |  ((x & (0x1 << bit2)) >> (bit2 - bit1)));

printf("after swapping: %x\n",x);
}
