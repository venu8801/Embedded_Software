#include<stdio.h>
void main()
{
	int i,j,k = 1;

	for(i = 4; i >= 0; i--){
		for(j = 0; j < ( 5 - i); j++){
			printf("%d ",k);
		}
		printf("\n");
		k++;
	}
}

