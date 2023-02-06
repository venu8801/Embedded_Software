#include<stdio.h>
#include"gopal.h"
void main()
{
	int num,bit, ret = 0;

	printf("Enter the num: ");
	scanf("%x",&num);

	printf("to set a bit\n");
	
	printf("Enter the bit num: ");
	scanf("%d",&bit);

	ret = set_bit(num,bit);

	printf("after setting a bit: 0x%x",ret);
}
