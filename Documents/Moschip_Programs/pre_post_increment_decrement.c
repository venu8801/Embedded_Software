/*this program showcases post/pre increment/decrement */
#include<stdio.h>
void main()
{	
	int x, y;

	x = 3;


	printf(" x = %d\n",x); 
	
	y = ++x; // pre increment first increments then assigns
	

	printf("------------Pre increment---------------");

	printf("y = %d\n", y); // prints y = 4

	printf("x = %d\n", x); // prints x = 4

	x = 3;

	y = x++; // post increment first assigns then increments

	printf("------------Post increment-------------");	

	printf("y = %d\n", y); // prints y = 3 
	
	printf("x = %d\n", x); // prints x = 4
}
