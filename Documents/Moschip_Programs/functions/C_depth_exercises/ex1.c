#include<stdio.h>
void main()
{
	printf("Lucknow\n");
	goto ab; 
	// it searches for label ab with in the main function 
	// if not found then tells label undefined 
	// goto can only be used within the function
}
void func(void)
{
	ab:
	printf("Bareilly\n");
}
