#include<stdio.h>
void main()
{
	double sum = 1.364;
	float sumf = 59.39;

	double *dptr = NULL;

	dptr = &sum; // this will store address of sum in dptr pointer variable

	printf(" data: %f -- address: %p\n",sumf, &sum); // finding address and data without using pointer variable
	
	printf(" data: %lf -- address: %p\n",*dptr, dptr); // finding address and data using pointer variable
}


