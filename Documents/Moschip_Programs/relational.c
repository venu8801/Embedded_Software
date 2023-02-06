#include<stdio.h>
void main()
{
	int a = 5, b = 7;

	int x;

	/* expressions containing relational operators are
	 * called relational expressions*/

	
	x = a > b; // if the relational is
       //	true then the value of expression is 1 if not then value is 0

	int z = a < b; // here b is greater than zero which is true
		// so the value of the expression is 1
	

	printf("value for a > b %d\n",x);
	printf("value for b > a %d\n",z);


}
