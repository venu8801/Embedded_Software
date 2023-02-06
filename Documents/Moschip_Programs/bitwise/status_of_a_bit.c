// this is a program to find out the status of a particular bit
#include<stdio.h>
void main()
{
	unsigned int num;

	unsigned short int bit;

	printf("Enter the number: ");

	scanf("%x",&num);
	
	printf("Enter the bit num: ");
	
	scanf("%d",&bit);

	 ( (num & (0x1 << bit)) == 0 )? printf("The bit is zero") : printf("The bit is one");
}

