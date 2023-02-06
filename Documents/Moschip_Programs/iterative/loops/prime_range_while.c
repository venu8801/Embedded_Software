// this is a program to print prime numbers in the given range
#include<stdio.h>
void main()
{
	int num, count = 0, min , max, i = 1;

	printf("Enter min and max range min:max");

	scanf("%d:%d",&min,&max);

	while(min <= max){


		num = min;
		while(i <= num){
			if(num % i == 0)
				count++;
			i++;
		}
		if(count == 2) 
			printf("%d\n",min);
		min++;
		count = 0;
		i = 1;
	}
}
