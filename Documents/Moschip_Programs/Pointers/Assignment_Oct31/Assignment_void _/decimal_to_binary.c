#include<stdio.h>
void decimal_binary(void *ptr, int n)
{
	int rem, bin = 0, i = 1, num;
	int j;
	for(j = 0; j < n; j++)
	{
		num = *((int *)ptr + j);
		rem = 0;
		i = 1;
		bin = 0;

		while( num != 0 )
		{
			rem = num % 2;

			bin = bin + rem*i;

			num = num / 2;

			i = i * 10;
		}

	printf("%p----%d\n",&((int *)ptr)[i],bin);
	
	}
}
