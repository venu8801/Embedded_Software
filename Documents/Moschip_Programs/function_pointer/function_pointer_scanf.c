#include<stdio.h>
void main()
{

	int num;


	int (*Pptr)(const char*,...); // pointer of printf type's type
	int (*Sptr)(const char*,...);// pointer of scanf type's type

	Pptr = printf;// assigning printf funcitons base address to Pptr
	Sptr = scanf; // assigning scanf functions base address to Sptr
	
	Pptr("Enter a num:");
	Sptr("%d",&num); // calling scanf using Sptr
	Pptr("num: %d\n",num);

	

}


