
//incrementing data inside pointers(addresses of other variables/memory locations) 
#include<stdio.h>
void main()
{
	int a = 5;

	int b = 6;

	int *pa = &a;

	int *pb = &b;

	
	printf("%d--------%p\n",*pa, pa);


	printf("%d--------%p\n",*pb, pb);
	
	pa++; // increments address by 4 bytes as data type of pa is int * 

	--pb;

	
	printf("%d--------%p\n",*pa, pa);

	printf("%d--------%p\n",*pb, pb);
}


