// this is a porgram to write numbers in reverse order with a difference of 2
#include<stdio.h>
void main()
{
	int min, max;

	int temp = min;

	printf("Enter a range in format min:max");

	scanf("%d:%d",&min,&max);

	while(max  >=  min){
		printf("%d\n",max);
		max = max - 2;
	}
}
