#include<stdio.h>
void main()
{
	int dec, rem, rev = 0, i = 1;

	printf("Enter Decimal number to be converted: ");
	
	scanf("%d",&dec);

	int temp = dec;

	while(temp !=0 ){

		rem = temp % 2;

		temp = temp / 2;

		rev = rev + (i * rem);

		i = i * 10;

		
	}
	printf("%d\n",rev);
}
