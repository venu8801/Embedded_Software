#include<stdio.h>
#include<limits.h>
int main()
{
	int short num = 89;
	/* printf function prints a strings until it finds a null character in it "\0" 
	 * after that it stops printing as null character represents end of string*/
	printf("hello m\n\0oshcip\n"); // only hello m only gets printed on screen
	// the character after null doesnt print 

	/* percentage i "%i" i the generic format specifier for integer data type"*/
	printf("Integer:%i\n",num); 

	printf("size is:%i\n",sizeof(num));
	

	char name[4] = {'a','b','c','\0'};
	printf("%s",name);
	

	long int n;
       printf(" >>  %ld ",LONG_MAX); 	
	
}


