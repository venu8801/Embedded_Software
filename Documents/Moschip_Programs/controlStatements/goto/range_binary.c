#include<stdio.h>
void main()
{
	int min,max,bin = 0,i = 1, temp=0,rem=0;

	printf("Enter the range in min:max foramt: ");
	scanf("%d:%d",&min,&max);
		
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
