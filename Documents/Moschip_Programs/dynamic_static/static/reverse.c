int reverse(int num) // function to reverse a number
{
	int digit = 0, rev = 0, temp = num;

	while(temp!=0)
	{
		digit=temp%10;
		rev=(rev*10)+digit;
		temp=temp/10;
	}
	return rev;
}
