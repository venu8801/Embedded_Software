#include<stdio.h>
void main()
{
	int num, temp, rev = 0, min, max, rem;


	printf("Enter range in format min:max ");

	scanf("%d:%d",&min,&max);

	while(min <= max){
		
		temp = min;
		while(temp > 0){
			rem = temp % 10;

			temp = temp / 10;

			rev = rem + rev*10;
		}
		if(rev == min)
			printf("%d\n",rev);
		min++;
		rem = 0;
		rev = 0;
	}
}

