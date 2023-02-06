#include<stdio.h>
void main()
{
	char x;

	printf("enter an alphabet");

	scanf("%c",&x);

	if( (x > 64) && (x <123)){
		if( (x > 64) && ( x < 91)){
			printf("o/p: %c\n",x + 32);
		}
		else{
			if((x > 96) && (x <123)){
				printf("o/p : %c\n",x-32);
			}
			else printf("Not a valid character");
			}
		}
		
	else printf("not a valid character");
}
		

