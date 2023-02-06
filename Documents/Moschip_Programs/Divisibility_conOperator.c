#include<stdio.h>
void main()
{

	int num;

	printf("Enter the number: ");

	scanf("%d",&num);

	(num % 5 == 0) ? printf("\nDivisible by 5") : printf("\nNot divisible by 5");


}
