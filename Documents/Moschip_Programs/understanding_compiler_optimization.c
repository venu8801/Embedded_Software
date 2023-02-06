#include<stdio.h>
void main()
{
	int x = 1;
	int y = 0;

	((x>0)||(printf("hello\n")))? printf("T"):printf("F");
	printf("%d and %d",x,y);
}


