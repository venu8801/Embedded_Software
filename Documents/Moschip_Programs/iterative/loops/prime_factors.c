#include<stdio.h>
void main()
{
	int num, count = 0, i = 1, j;

	printf("Enter a number to print its prime factors: ");
	scanf("%d",&num);
	printf("entered: %d \n",num);
	while(i <= num)
	{
		count = 0;
		if(num % i == 0) // if it is a factor or not
		{	
			// if yes, then check if 'i' prime or not
			for(j = 1; j <= i; j++)
			{
				if(i % j == 0)
					count++;
			}
			if(count == 2)
			{
				printf("%d ",i);
				num = num / i; // to reduce num 
				i =  i - 1; // to check with i again
			}
			       		
		}
		i++;

		
	}

}	
