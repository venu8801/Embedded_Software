/* use only pointers
* inputs x = 0x11223344;
* y = 0xaabbccdd swap and store in z = 0xaa22cc44*/


#include<stdio.h>
void main()
{
	unsigned int x = 0x11223344;
	
	printf("Enter value of x in hexa-decimal: ");
	scanf("%x",&x);

	unsigned int y = 0xaabbccdd;
	printf("Enter value of y in hexa-decimal: ");
	scanf("%x",&y);
	unsigned int z = 0x0;

	int *xptr = &x;
	int *yptr = &y;
	int i = 0;
	char *ptr = &z;

	/*for(i = 0; i < 4; i = i + 2)
	{
		
		//printf("0x%x\n", ((char *) xptr)[2]);
		*(ptr + i)  =  ((char *)xptr)[i] ;
	}
	for(i = 1; i < 4 ; i = i + 2)
	{
		
		//printf("0x%x\n", ((char *) xptr)[2]);
		*(ptr + i)  =  ((char *)yptr)[i] ;
	}
*/
	for(i = 0; i <= 4; i++)
	{
		if(i % 2 == 0)
		{
			*(ptr + i)  =  ((char *)xptr)[i];
		}
		else
			*(ptr + i)  =  ((char *)yptr)[i];
	}
			
	printf("0x%x\n",z);





}
