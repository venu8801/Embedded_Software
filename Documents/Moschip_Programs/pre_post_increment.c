#include<stdio.h>
void main()
{
	int x = 5;


	printf("pre increment: %d\n",++x);// value 6 gets printed 
       	// pre increment values gets incremented first and gets assigned and prints

	x = 9; 
	printf("post increment:%d\n",x++);// value 9 gets printed directly
       	// post increment means values gets substituted first and later gets updated
	// so value without incrementation prints as it gets submitted first later it gets updated in variable
}

