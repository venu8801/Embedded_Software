#include<stdio.h>
void main()
{
	unsigned int x = 0x11223344;

	unsigned int y = 0;

	printf("entered value: 0x%x\n",x);
	y = (  ((x & (0xff << 16) ) >> 16 ) | ((x & (0xff << 0) ) << 8)  );

	printf("0x%x\n",y);

}
