#include<stdio.h>
int main()
{
	char str[] = "welcome\n";  // this stores 
		/* (-w e l c o m e \n-) total 8 + 1 null character
		 * the length is calculated excluding null character
		 * if we print the above string using printf func. we 
		 * it should return length as 8 but */
	
	
	/* length of string and size are different length is measure of 
	 * no. of characters in string and size is the space occupied by 
	 * the string in memory */

	/* this string gets stored in ram memory not in ro data segment*/


	int returned = printf(str); // prints string even if no format specifier is used
	
	printf("size is : %d bytes, length is: %d characters\n", sizeof(str), returned); 
	
	printf();
	
	return 0;
}
