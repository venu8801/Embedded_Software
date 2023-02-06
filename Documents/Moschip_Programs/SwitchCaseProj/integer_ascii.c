char integer_ascii(char ascii)
{
	if(ascii >= 48 && ascii <= 57)
	{
		return ascii - 48;
	}
	else return -1;
}

