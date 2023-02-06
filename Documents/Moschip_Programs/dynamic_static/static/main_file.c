#include<stdio.h>
#include"gopal.h"
void main()
{
	int num,bit, ret = 0;

	printf("Enter the num: ");
	scanf("%d",&num);

	
	//ret = reverse(num);
	
	ret = sum_digits(num);
	
	

	//printf("reverse: %d",ret);
	printf("sum of digits: %d",ret);
}
