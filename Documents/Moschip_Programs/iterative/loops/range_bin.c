// write a program to print binary values in given range skipping non binary decimal values
#include<stdio.h>
void main()
{
	int min, max, temp, rem, bin = 0, i = 1;

	printf("Enter range of values min:max");

	scanf("%d:%d",&min,&max);

	while(min <= max){
		temp = min;
	
		bin = 0;

		i = 1;

		while(temp != 0){
			rem = temp % 10;

				if(rem > 1){
				      min++;
				       
				       break;
			       	       
				}
				temp = temp / 10;
				bin = bin + ( i * rem);

				i = i * 2;
		}
		if(rem > 1){ 
			min++;
			continue;

		}

		printf("%d-----%d\n",min, bin);

		min++;

	}
}
