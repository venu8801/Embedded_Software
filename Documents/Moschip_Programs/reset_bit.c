/* program to understand clear/resetting a bit */
#include<stdio.h>
void main()
{
	unsigned char x = 0xff;

	// reset 5th bit in x
	// to reset a bit and operation with 0 needs to be performed with that
	// specific bit
	// 1111 1111 && 1101 1111 will result in resetting or clearing of bit5
	// 1101 1111 in hex is 0xDF 
	
	x = x & 0xDF;

	/* or */

	/* we can also use negation of 5th bit setting to obtain 5th bit 
	 * clearing the 5th bit setting is 0x20 --> 0010 0000  negation of 
	 * this is ~(0x20) which is 0xDF --> 1101 1111 */

	/* x = x && (~(0x20)) // this can also be used instead of the above one
				*/

	printf("%X\n",x);

}
