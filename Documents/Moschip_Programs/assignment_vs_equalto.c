#include<stdio.h>
void main()
??<
	int a,b;
	a = 3, b = 5;

	/* assignment operator is different from equal to operator
	 * assignment means assigning values but equal to is a relational 
	 * operator which compares two values*/

	// let us understand difference b/w assignment and realtional operator
	// equal to
	
	if (a < b){// this relational expression becomes 1(non-zero) when a < b=
		printf("a is lesser than b\n");

	}

	if( a = b){
		printf("a ------ b\n");
	} // here this statement gets executed as a gets assigned to b and value of whole expression becomes non zero

	if(a == b){
		printf("a and b are equal\n");
	} // this statement gets executed if realtional expression becomes non zzero , it becomes non zero only when a and b are equal 

	if(0){
		
		printf("zero\n");
	}
	if(1){
		printf("one\n");
	}

??>
