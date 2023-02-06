#include<stdio.h>
#define PI 3.1415926
void main()
{
	// this is a program which takes radius as input from user and prints \
	// area and perimeter of a circle as output
	float radi;

	printf("Enter radius of circle:");

	scanf("%f",&radi);

	float area = PI * radi * radi;

	float perimeter = 2 * PI * radi;
	printf("Area is:%.3f and Perimeter is:%.3f\n",area,perimeter);

}

