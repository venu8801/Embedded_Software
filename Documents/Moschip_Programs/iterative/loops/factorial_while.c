// this is a program to print factorial of a number using while loop
#include<stdio.h>
void main()
{
	unsigned  long long int num, fact = 1;
	

	printf("Enter a number: ");

	scanf("%lld",&num);

	while(num > 1){

		fact = fact * num;
		num--;
	}
	printf("factorial: %lld\n",fact);
	printf("size is: %ld bytes\n",sizeof(fact));

}
