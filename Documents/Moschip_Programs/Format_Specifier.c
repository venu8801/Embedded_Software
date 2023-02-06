#include<stdio.h>
int main()
{
	int x = 127; // stored in decimal format
	
	printf("For decimal value: 127"); // prints decimal equivalent of 127's binary
	printf("decimal: %d\n",127); // prints decimal equivalent of 127's binary
	printf("hex:0x%X\n", 127); // prints hex equivalent of 127
	printf("oct: 0%o\n",127);// prints oct equivalent of 127

	printf("-----------------------------------\n");


	int y = 0127; // stored in octal 

	
	printf("For octal value: 0127"); // prints decimal equivalent of 127's binary
	printf("decimal: %d\n",0127); // prints decimal equivalent of 127's binary
	printf("hex:0x%X\n", y); // prints hex equivalent of 127
	printf("oct: 0%o\n",y);// prints oct equivalent of 127

	return 0;
}
