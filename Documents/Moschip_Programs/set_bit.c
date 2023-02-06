#include<stdio.h>
void main()
{
	unsigned char x = 0xF0;

	// set 3rd bit in x
	
	// to set a bit we do or operation with 1 at that particular bit
	/* 0xF0 in binary is 1111 0000 if we want sent 3rd bit then we need to
	 * do or operation with 1 at 3rd bit position to set the 3rd bit to 1
	 * without effecting other bits to do this we do or operation of 0xF0 
	 * with 0x08 whose binary is 0000 1000 that bit is 1 here*/

	x = x | 0x08;

	printf("%x\n",x); // printing the result in hexa decimal
	
	// the output should be 0xF8
}
