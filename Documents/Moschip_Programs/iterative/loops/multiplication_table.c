// multiplication table
#include<stdio.h>
void main()
{
	int num, limit, temp;

	printf("Enter number to print its multiplication table: ");
	
	scanf("%d",&num);

	printf("Uptil what multiple ? :");

	scanf("%d",&limit);
	int i = 1;
	
	while(i <= limit){
		printf("%d x %d = %d\n", num, i, num * i);

		i++;
	}
}

