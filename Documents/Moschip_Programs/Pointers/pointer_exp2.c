#include<stdio.h>
void main()
{
	long int  x = 90;

	double *fptr = NULL;
	printf("%ld -- %p \n",fptr,fptr);
	fptr = &x;
	printf("%p -- %p \n",&x,fptr);
	
	*fptr = 20;

	printf("%p -- %p \n",fptr,&x);


	printf("%ld------- %d\n",*fptr,sizeof(x))i;

}

