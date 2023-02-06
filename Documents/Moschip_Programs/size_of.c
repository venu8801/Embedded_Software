#include<stdio.h>
int main()
{
	char s;


	printf("size of char is: %d byte(s)\n",sizeof(s));
	printf("size of int is: %d byte(s)\n",sizeof(int));
	printf("size of float is: %d byte(s)\n",sizeof(float));
	printf("size of long int is: %d byte(s)\n",sizeof(long int));
	printf("size of double is: %d byte(s)\n",sizeof(double));
	printf("size of double is: %d byte(s)\n",sizeof(&s));
	return 0;
	
}
