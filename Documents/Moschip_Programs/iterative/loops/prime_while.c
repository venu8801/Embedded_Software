// this is a program to find if a number is prime or not
#include<stdio.h>
void main()
{
	int num, count = 0,i = 1;

	printf("Enter a number: ");
	
	scanf("%d",&num);


	while( i <= num ){
		if(num % i == 0){
			count++;
		}
		i++;
	}
	if(count == 2){
		printf("The number is a prime\n");
	}
	else printf("This is not  a prime number\n");
}

