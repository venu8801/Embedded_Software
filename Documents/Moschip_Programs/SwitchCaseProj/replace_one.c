int replace_one(int num) // function for replacing 101 with 111
{
	int i = 0;
	unsigned int temp = num;
	for(i = 0; i < 31 - 2; i++)
	{
		if(( temp & (0x7 << i) ) == (0x5 << i))
		{
			temp = (temp | (0x7 << i));
		}

	}
	return temp;
}
