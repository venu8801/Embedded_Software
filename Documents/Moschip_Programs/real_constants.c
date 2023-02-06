#include<stdio.h>
int main()
{
	float x = 145.5; // only digits are present

	printf("  %g\n",x);// 6 digit output is printed 
	
	double z = 3.141414141414141414;// double precision
	/* in double precision upto 12 digits precision is maintained*/
	printf(" %lf \n",3.14141414141414);

//	float y = 15678.7879;// mantissa: 15678

	printf("\n  %E\n",y); // should print e+04
	
	printf( "%d ",3.141414);
	return 0;
}

