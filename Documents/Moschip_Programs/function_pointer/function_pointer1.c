#include<stdio.h>
void main()
{
	char arr[10] = "hello";

	// declaring a function pointer for printf
	int (*fptr) (const char*,...); // here function pointer should 
	// be of printf type

	fptr = printf;

	fptr("%s\n",arr);

}

