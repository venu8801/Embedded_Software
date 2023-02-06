#include<stdio.h>
unsigned int func(unsigned int num)
{
	unsigned int i,r = 0;
	for(i = 0; num!= 0; i++)
	{	
		printf("0x%x\n",r);
		r = r << 1 | num & 1;
		num >>= 1;
		printf("0x%x\n",num);

	}
	r << 32 - i;
	return r;
}
void main()
{
	unsigned int x = 0x1AE3;

	x = func(x);

	printf("0x%x\n",x);

}

