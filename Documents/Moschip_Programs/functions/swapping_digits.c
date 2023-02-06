#include<stdio.h>
 int swapping_first_last(int value);

void main()
{
	int num,ret;
	printf("Enter any integer: ");
	scanf("%d",&num);
	ret = swapping_first_last(num);
	printf(" after swapping: %d\n",ret);

}
 int swapping_first_last(int value)
{
	 int num = value;
	  int digit, l_digit, f_digit,ans, out,i = 1;

	while(num > 0)
	{
		digit = num % 10;
		if(i == 1)
			l_digit = digit;
		num = num / 10;
		i = i * 10;
	}
	f_digit = digit;
	i = i / 10;
	ans = value - ( f_digit * i + l_digit);

	out = l_digit*i + ans + f_digit;

	return out;
}
			
