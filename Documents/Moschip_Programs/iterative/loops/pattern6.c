
#include<stdio.h>
void main()
{
	int i, j, k,t;
	 k = 2;
	for(i = 5; i > 0; i--){ 
			for(j = 0; j < (5 - (i-1)) ; j++){
			printf("%d ",k);
			k++;
			
		}
		printf("\n");
		
	}
}
