#include<stdio.h>

int func(void);
void main()
{	
	int func(void)
	{
		printf("Function\n");
	}
	
	int x = 10;

	x = func();

	printf("%d\n",x);

}

/*int func(void)
{
	printf("Function\n");
}*/
