#include<stdio.h>
void main()
{
	int a ;

	printf("Enter the number:");

	scanf("%x",&a);

	int bit = 31;

	for(bit ; bit <= bit/2; bit++){
		a = (a & ~((0x1<<bit)|(0x1<< ( 31 - bit))) ) | (   (a & (0x1 << bit))<<(31 - bit))| a &( (0x1 << (31-bit))) ;
	}
	printf("0x%x\n",a);
}
