
int count_zeroes(int num) //function for counting the 0s
{
	int i = 0,count = 0;
	int temp;
	temp = num;
	for(i = 0; i <= 31; i++)
	{
		if( (temp & (0x1 << i)) == 0) count++;
	}
	return count;
}
