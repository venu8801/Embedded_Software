
#include<stdio.h>
int func(int,int,int);
void main()
{
	int ret;
	ret = func(1,2,3);
	
	printf("%d\n",ret);
}
int func(int a, int b, int c)
{
	int x;
	x = (a,b,c);
	printf("%d\n",x);
	
	return a,b,c;
}


