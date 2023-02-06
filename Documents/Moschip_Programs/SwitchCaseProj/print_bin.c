#include<stdio.h>
void print_bin(int num)// function for printing binary
{
	int i = 0;
	unsigned int temp = num;
	for(i = 31; i >= 0; i--)
	{
		if( (temp & (0x1 << i)) == 0)
			printf("0");
		else printf("1");
	}	
}
