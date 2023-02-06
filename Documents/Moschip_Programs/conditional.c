#include<stdio.h>
void main()
{
	// this is a program to find the largest of 2 numbers using conditional operators
	int a , b;

	printf("enter values of a,b in a,b format: ");

	scanf("%d,%d",&a,&b);


	/* syntax:----------> condition ? exp1 : exp2;*/

       	// if the condition is true expression 1 gets evaluated
       //	if flase expression 2 gets evaluated
       
       //----------------------------------------------//
       
       
	int big_number = ( a > b )? a:b; // if condition becomes true big_number is assigned with 'a' else assigned with 'b'

	/* the above can also be acheived by using these*/

	(a > b)? printf(" %d is bigger\n",a) : printf(" %d is bigger\n",b);

//	printf("\nthe bigger number of the two is %d\n",big_number);


}
