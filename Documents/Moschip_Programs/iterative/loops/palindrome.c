
// this is a program to find if a number is palindrome or not
#include<stdio.h>
void main()
{
	unsigned long int temp,num,rem, rev = 0;

	printf("Enter number : ");

	scanf("%ld",&temp);

	num = temp;

	while(num != 0){
		rem = num % 10;

		num = num / 10;

		rev = rem + rev * 10;

	}
	printf("Reversed Value: %ld\n",rev);

	if(temp == rev){
		printf("Is a palindrome");
	}
	else printf("Not a palindrome");


}
