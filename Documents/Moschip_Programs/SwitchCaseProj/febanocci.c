#include<stdio.h>

void febanocci(int x, int y, int k)
{
	int z = 0;
	printf(" %d %d ",x,y);
	while(z < k){


		x = y;
		y = z;
		z = x + y;
		if(z < k)
			printf("%d ",z);

	}
}


