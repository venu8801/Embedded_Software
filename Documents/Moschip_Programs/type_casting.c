#include<stdio.h>
void main()
{
	unsigned int x = 0xaabbccdd;

	unsigned int y;

	y = (char)x; // type casted to signed char from unsigned int 

	printf("%x\n",y); 

	y = x;

	printf("%x\n",y);
}
