#include<stdio.h>
void main()
{
	/*unsigned int x;

	printf("Enter unsigned int in hex format: ");

	scanf("%x",&x);

	( (x & (0x1 << 3)) == (x & (0x1 << 7)) )? printf("No swap:%x\n",x) : 
	       ( x = (x ^ (1 << 3) | (1 << 7)));

		printf("Result:%x\n",x);*/
unsigned int x;

	printf("Enter unsigned int in hex format: ");

	scanf("%x",&x);

	( ( ( (x & (0x1 << 3)) == 0x8) && ((x & (0x1 << 7)) == 0x80 ) ) || ( ( (x & ( 0x1 <<3)) == 0) && ((x & ( 0x1 << 7)) == 0 ) ) ) ? 

		printf("No swap required\n") :  ( x = (x ^ (1 << 3) | (1 << 7)));

		printf("Result:0x%x\n",x);

}
