
#include<stdio.h>
void main()
{
	double a = 5.3;

	double b = 6.3;

	double *pa = &a;

	double *pb = &b;

	
	printf("%lf--------%p\n",*pa, pa);


	printf("%lf--------%p\n",*pb, pb);
	
	pa++;

	--pb;

	
	printf("%lf--------%p\n",*pa, pa);

	printf("%lf--------%p\n",*pb, pb);
}


