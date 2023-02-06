#include <stdio.h>

main()
{
	 int y,x,z;


	printf("enter bulb no:");
	 
	scanf("%d",&y);
	 z = 2;
	x = y - 1;
	
	for(int i = 1; i <= x; i++)
	{
	z = z * 2;


         }
       printf("stored value: %d\n", z);
	printf("Bulb %d is ON:",y);
}
