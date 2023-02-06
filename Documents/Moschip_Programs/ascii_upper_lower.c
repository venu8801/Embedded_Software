#include<stdio.h>
void main()
{
	char y;
	printf("Enter a single character:");
	scanf("%c",&y);

	((y > 64) && (y < 91))? printf("UPPER CASE") :
	  	((y > 96) && (y < 124)? printf("lower case")
		 : printf("NOT ALPHABET"));
}
