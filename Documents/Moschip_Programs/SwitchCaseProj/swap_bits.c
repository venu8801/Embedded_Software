int swap_bits(int num, int b1, int b2)
{	

	unsigned int temp = num;
	if(b1 > b2)
		temp = b1,b1 = b2, b2 = temp;
	temp = ( (num & ~((0x1<<b1)|(0x1<<b2)) ) | ( ( num & (0x1 << b1)) >> (b1 -b2) ) |( ( num & (0x1 << b2)) << (b1 -b2) ) );
	return temp;
}
