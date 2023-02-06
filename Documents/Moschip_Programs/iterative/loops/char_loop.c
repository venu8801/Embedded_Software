// while loop with signed char


#include<stdio.h>
void main()
{
	char x = 1; // signed char range is -128 to 127

	while(x > 0){ 
		x++;// x post increment 
	}
	printf("%d\n",x);
}
