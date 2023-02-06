#include<stdio.h>
void main()
{	
	int a , b;
	printf("%p\n",&a);
	int func(int a, int b)
	{	
		hbdpranav:
		printf("%p\n",&a);
		return a + b;
	}
	int c;
	goto hbdpranav;
	c = func(3,5);
	printf("%d\n",c);
}
