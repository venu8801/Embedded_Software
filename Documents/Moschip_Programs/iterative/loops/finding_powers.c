//this is a program to find the power of a number
#include<stdio.h>
void main()
{
	int base, power = 1, ans = 1;

	printf("Enter the base: ");

	scanf("%d",&base);

	printf("Enter the power: ");

	scanf("%d",&power);
	 
	int i = 0;

	while(i < power  ){
		
		ans = ans * base;

		

		i++;
	}


	printf(" %d ^ %d is = %d\n",base, power, ans);

}



		
