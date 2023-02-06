char upper_lower(char ascii)
{
	if(ascii >= 65 && ascii <= 122){
		if(ascii < 91)
			return ascii +  32;
		else if(ascii < 123)
			return ascii - 32;
		else return -1;
	}
	else return -2;
}
