// this is a program to print values in a range in reverse order using while loop
#include<stdio.h>
void main()
{	
	int min,max;
	printf("Enter values in range\n");
	printf("Enter values in \"min-max\" format: ");

	scanf("%d-%d",&min,&max);

	while( max >= 0){
		printf("%d\n",max);
		max--;
	}
}

