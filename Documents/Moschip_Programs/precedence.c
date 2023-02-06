#include<stdio.h>
void main()
{
	int a = 8, b = 4, c = 2, d = 1 , e = 5, f= 20;

	printf("%d\n",a+b-(c+d)*3%e+f/9);

	a = 17, b = 5, c = 6, d = 3, e= 5;

	printf("%d\n",a%6-b/2+(c*d-5)/e);

}
