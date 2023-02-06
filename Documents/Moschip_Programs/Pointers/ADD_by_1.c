
#include<stdio.h>
void main()
{
	int a = 5;

	int b = 6;

	int *pa = &a;

	int *pb = &b;

	
	printf("%d--------%p\n",*pa, pa);


	printf("%d--------%p\n",*pb, pb);
	
	pa=pa+1;

	pb=1+pb;

	
	printf("%d--------%p\n",*pa, pa);

	printf("%d--------%p\n",*pb, pb);
}


