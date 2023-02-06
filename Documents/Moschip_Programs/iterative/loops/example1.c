#include<stdio.h>
void main()
{
	// write a program to display no. of digits beside the range
	int num, min, max, count = 0;

	printf("Enter min and max values in \"min-max\" format:");

	scanf("%d-%d",&min,&max);

	printf("Number - Digits\n");
	
	while(min <= max){
		printf("%d   -   ",min);
	
			if(min!= 0)
			{	
				num = min;
				while(num > 0)
				{
				num = num / 10;
				count++;
				} 
			}
			else count++;
	

		printf("%d \n",count);
		count = 0;
		min++;
	}
}
			
