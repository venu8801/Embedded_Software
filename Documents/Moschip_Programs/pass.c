#include<stdio.h>
void main()
{
	char pass[32];

	printf("enter string:");
	//scanf("%[^\n]",pass);
	
	gets(pass);

	puts(pass);
	printf("entered string: %s",pass);
}
