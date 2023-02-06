#include<stdio.h>
#include<limits.h>
void main()
{
	long int num,temp;
	int digit,s_max = 0,max = UINT_MAX;
	printf("enter the num: ");
	scanf("%ld",&num);
	temp = num;
	while(temp > 0)
	{
		digit = temp % 10;

		if(digit > max)
		{
			s_max = max;
			max = digit;
		}
		temp = temp/10;
	}
	printf("second Biggest:%d\n",s_max);
}





