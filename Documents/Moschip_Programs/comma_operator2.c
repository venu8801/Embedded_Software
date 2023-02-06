#include<stdio.h>
/*void main()
{
	int x = 5, y = 20, z;


	z = (x,
		printf("x gets assigned to z--z = %d\n",z), 
		       	y = 50,
		       		printf("y gets assigned with 50 -- y = %d and z = %d\n",y,z),
		       			(z = 40,
				       		printf(" z gets assinged with 40 -- z = %d\n",z),
		       					x + y + z,
						       		)
			); //z gets updated with retrun value of printf(--)
			
			
			printf("%d--%d--%d\n",x,y,z);
			}  /*----------------------*/
void main()
	
{
	int x = 5, y = 20, z;


	z = (x, y = 50, (z = 40, x+y+z));
			
			
			printf("%d--%d--%d\n",x,y,z);
}
