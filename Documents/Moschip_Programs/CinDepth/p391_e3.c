#include<stdio.h>
void main()
{
	int k =  0xffffbbdd;
//	k = ((3 << 4) ^ (96 >> 1));
	
	
//	printf("0x%x\n",k);

	k =  k >> 17;

	printf("0x%x\n",k);
}
