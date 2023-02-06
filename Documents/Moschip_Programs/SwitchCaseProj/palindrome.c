
int palindrome(int num) // function to check palindrome
{
	int temp = num;
	int digit = 0, rev = 0;
	while(temp > 0)
	{
		digit = temp % 10;
		temp = temp / 10;

		rev = digit + rev * 10;
	}
	return rev;
}
