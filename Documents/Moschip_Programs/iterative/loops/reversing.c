// this is a program to reverse a number
#include<stdio.h>
void main()
{
	unsigned long int num,rem, rev = 0;

	printf("Enter number to reverse: ");

	scanf("%ld",&num);

	while(num != 0){
		rem = num % 10;

		num = num / 10;

		rev = rem + rev * 10;

	}
	printf("Reversed Value: %ld\n",rev);
}
