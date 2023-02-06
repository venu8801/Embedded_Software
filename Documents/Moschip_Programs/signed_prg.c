#include<stdio.h>
int main()
{
	signed  x = - 1; // signed int  variable
	// %u accepts only positive integers so if -ve sign assigned
	// it will take reverse of 2s complement for unsigned format 
	// specifier
	printf(" %d and %u" ,x,x);
}
