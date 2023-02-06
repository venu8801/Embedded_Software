#include<stdio.h>
void main()
{
	int x = 5, y = 20, z;

	z = x, printf("x gets assigned to z = %d\n",z), x + y, printf("x + y gets added not assigned %d\n",x + y), x + y + 20, printf("x+y+z gets added"), x = 20, printf("x gets assigned with value 20 x : %d\n", z);

	printf("%d--%d--%d\n",x,y,z);

}
