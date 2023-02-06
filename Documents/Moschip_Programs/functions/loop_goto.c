#include<stdio.h>
void bin_range(int s, int e);
void main()
{
	int min,max;
	printf("Enter the range in min:max foramt: ");
	scanf("%d:%d",&min,&max);
	bin_range(min,max);
	
}

void bin_range(int s, int e)
{
	int min = s, max = e;
	int bin = 0,i = 1, temp=0,rem=0;
outer:
		bin = 0;
		i = 1;
		temp = min;
	
		
			inner:
				rem = temp % 10;
				if(rem > 1){
					min++;
					goto outer;
				}	
				temp  = temp/ 10;
				bin = bin + (rem * i);
				i = i * 2;
				if(temp!=0)
					goto inner;
				printf("%d---%d\n",min,bin);
				min++;
				if(min<=max)
					goto outer;
}
