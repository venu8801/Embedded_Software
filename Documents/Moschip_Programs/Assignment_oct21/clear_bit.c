int clear_bit(int num, int bit)
{
	unsigned int a = num;

	a = (a & ~(0x1 << bit) );

	return a;
}
