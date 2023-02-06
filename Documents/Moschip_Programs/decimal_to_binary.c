#include<stdio.h>
void main()
{	
	int decimal, binary;

	printf("enter decimal number:");

	scanf("%d",&decimal);

	while( decimal > 0)
	{	
		int rem = decimal % 2;
		rem = rem +  rem * 10;
		decimal = decimal/2;
		binary  = rem;

	}

	printf("Binary:%d",binary);



}
