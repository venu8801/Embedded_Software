#include<stdio.h>
int main()
{
	int a,b;

	printf("enter value of a:");
	
	scanf("A is:%d",&a);
	__fpurge(stdin);

	printf("\nenter value of b:");
	scanf("B is:%d",&b);

	printf("entered values are: %d and %d",a,b);

	return 0;
}

