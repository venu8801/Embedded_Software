int sum_digits(int num)// function for sum of digits
{
	int temp = num;
	int digit = 0, sum = 0;
	while(temp > 0)
	{
		digit = temp % 10;

		temp = temp / 10;

		sum = sum + digit;
	}
	return sum;
}	
