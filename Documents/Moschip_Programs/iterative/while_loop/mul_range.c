/* this is a program to print multiplication table vertically*/
#include<stdio.h>
void main()
{
	int start,end, i = 1;

	printf("Enter the values of start,end :");
	scanf("%d,%d",&start,&end);


	while(start <= end)
	{

		i = 1;

		while(i <= 10)
		{
			printf("%d x %d = %d\n",start,i,start*i);

			i++;
		}
		printf("----------------\n");
		printf("\n");

		start++;
	}

}


