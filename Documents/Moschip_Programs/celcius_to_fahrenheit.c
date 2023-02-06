#include<stdio.h>
void main()
{
	float temp_celcius;

	printf("Enter temperature in celcius:" );

	scanf("%f",&temp_celcius);

	printf("Temperature in fahrenheit: %.2f degrees",((temp_celcius * 9)/5) + 32);
}


