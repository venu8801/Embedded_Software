/*1. Write a program in C to display the sum of the series [ 9 + 99 + 999 + 9999 ...]. Go to the editor
Test Data :
Input the number or terms :5
Expected Output :
9 99 999 9999 99999
The sum of the saries = 111105*/

#include<stdio.h>
void main()
{
	int num = 9, i = 1, terms, sum = 0;
	printf("Enter the num of terms:");
	scanf("%d",&terms);

	printf("%d\t",num);
	while(i < terms)
	{
		
		num = ((num * 10) + 9);
		sum = sum + num;
		printf("%d\t",num);
		i++;
	}
	printf("\nthe sum of series is:%d\n",sum);
}


