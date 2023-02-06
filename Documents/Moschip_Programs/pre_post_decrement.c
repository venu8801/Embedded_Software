
#include<stdio.h>
void main()
{
	int x = 5;


	printf("pre increment: %d\n",--x);// value 4 gets printed 
       	// pre decrement values gets decremented first and gets assigned and prints

	x = 9; 
	printf("post increment:%d\n",x--);// value 9 gets printed directly
       	// post decrement means values gets substituted first and later gets updated
	// so value without decrementation prints as it gets submitted first later it gets updated in variable
}

