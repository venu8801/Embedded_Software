// c program to print odd numbers in the given range
#include<stdio.h>
void main()
{
	int min, max, temp;

	printf("Enter the min:max values: ");

	scanf("%d:%d",&min,&max);

	temp = min;

	while(min <= max){
		if(min % 2 == 0){
			min++;
			continue;
		}
		else printf("%d\n",min);
		
		min++;
	}
}
