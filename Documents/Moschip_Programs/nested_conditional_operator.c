#include<stdio.h>
void main()
{

	/* thid is a program to understand nested conditional operators*/

	int x,y,z;

	printf("enter values of x,y,z using commas in b/w: ");

	scanf("%d,%d,%d",&x,&y,&z);

	// nested conditional operator is used when we have to compare more operands or need to check multiple cases
	
	int big = (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
//		   ^inner-condition     ^inner-condtion 
//		  of  exp1 		of exp2

//	^condition     ^expression1 	^expression2

	
/* if the condition x > y turns to be true the expression1 will be evaluated and expression2 will be ignored
 * there is a nested condition inside expression1 which will be checked again and evaluates inner condition's expressions*
 */

	printf("\n the bigger number is:%d",big);
	

}
