#include<stdio.h>
void main()
{
	unsigned int temp = 0x55,res;

	res = temp & (0x7 << 2);

	printf("0x%x\n",res);
}

