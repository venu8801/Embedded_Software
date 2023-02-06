
#include<stdio.h>
void main()
{	
	float v = 1.32; // a normal variable with char data type
	float *cptr;  // declaring a pointer variable

	int *iptr = &v;	

	cptr = &v; // storing address of v in cptr variable

	printf("%c and %p\n",v,&v);

	printf("%c and %p\n",*cptr,cptr);

	*cptr = 'b';
	printf("%c and %p\n",*cptr,cptr);

	printf("size of pointer: %d\n",sizeof(cptr)); // prints size of pointer depends on machine type

	
	printf("size of address of v: %d\n",sizeof(&v)); // prints size of address of v which is 8 for a 64bit machine
	printf("size of data in *cptr : %d\n",sizeof(*iptr)); // prints size of address of v which is 8 for a 64bit machine
}
