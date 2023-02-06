#include<stdio.h>
void main()
{
	int a ;

	a = (0xFF >> 8) << 8; // 4 byte value of this in hex is 0x 00 00 00 FF here the msb is zero so if shited right it the resultant is zeroes
	// even if the result is again left shifted as the whole value is 0 the overall output would be zero

	printf("%x\n",a);
}


