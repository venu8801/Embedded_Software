// c program to find the right most set bit
#include<stdio.h>
void main()
{
	int a;

	printf("Enter the value of a:");

	scanf("%x",&a);

	int bit = 0 ;

	while(bit <= 31){
		printf("--\n");
		if( (a & (0x1 << bit)) == 0)
			printf(" The right most set bit is: %d\n",bit);
			break;

		bit++;
		}
}



