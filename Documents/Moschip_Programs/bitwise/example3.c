#include<stdio.h>
void main()
{
	int x = 7, y = 19;

	printf(" %d  %d",x&y,x&&y);
	printf(" %d  %d",x|y,x||y);
	printf(" %d ",x^y);
}
