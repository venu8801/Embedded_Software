#include<stdio.h>
#include<signal.h>
void main()
{	
	int i = 0;
	while(1)
	{
		printf("%d",i);
		if(i >= 15)
			raise(9);
		i++;

	}	
}
