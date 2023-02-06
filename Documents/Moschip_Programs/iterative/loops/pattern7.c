
#include<stdio.h>
void main()
{
	int i, j, k;

	for(i = 5; i > 0; i--){
		k = 5;
		for(j = 0; j < (5 - (i-1)) ; j++){
			printf("%d ",k);
			k--;
		}
		printf("\n");
	}
}
