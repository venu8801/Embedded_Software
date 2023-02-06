#include<stdio.h>
void main()
{
	unsigned int x = 0xaabbccdd;

	unsigned char *ptr = &x;


	int i = 0;

	for(i = 0; i < 4;i++)
	{
		printf("0x%x----%p\n",*ptr,ptr);
		ptr++;
		}
}

