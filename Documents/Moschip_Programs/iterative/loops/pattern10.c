#include<stdio.h>
void main()
{
	int i = 0, j = 0, k;


	for(i = 0; i < 5; i++){

		k = i + 1;

		for(j = 5; j > (5 - i - 1); j--){

			printf("%d ", k);

			k++;
		}

		printf("\n");
	}
}
