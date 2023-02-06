#include<stdio.h>
int main()
{
	unsigned x = 48; // variable named x with no data type 


       	// here data type is missing but sign qualifier is present
	
	/* if sign qualifier is present and data type is missing in this 
	 * case it is considered as int by the compiler */

	printf("ASCII-%c and DECIMAL:  %d \n",x,x);

	printf("size is %d",sizeof(x)); // it can be verified if it int or not

	return 0;
}
