int count_digits(int num)
{
	int count = 0, temp = num;	
	if(temp!=0)
	{
		while(temp!=0)
		{
			temp=temp/10;
			count++;
		}
	}
	else
		count++;
	return count;
}
