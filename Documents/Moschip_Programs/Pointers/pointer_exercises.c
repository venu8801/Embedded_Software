//understanding significance of precedence on dereferenced pointers 
#include<stdio.h>
void main()
{
	int x = 10;

	int *iptr;

	iptr = &x;

	printf("%d---%p\n",*iptr,iptr);

	*iptr++;  // this is postfix increment as the order of evaluation is from right to left
	// this expression is treated as *(iptr++) where it increments the address of iptr by its data type times and dereferences it

	// here as there are no other variables so if address incremented by 4bytes and de referenced we may get a garbage value (or) segmentation fault
	
	printf("--%d-----%p \n",*iptr,*iptr);
	
	printf("%d---%p\n",x,&x);
}
