#include<stdio.h>
void swap_bitwise(int x, int y)
{
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;	

	printf("After swapping x=%d and y=%d\n",x,y);

}
