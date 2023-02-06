#include <stdio.h>
int main()
{
	int size , sum = 0;
	printf("\nEnter size of array: ");
	scanf("%d",&size);
	int arr[size];
	for (int i = 0; i < size; i++){
		printf("\nenter %d element: ",i+1);
		scanf("%d",&arr[i]);
	}
	for(int i = 0; i < size; i++){
		sum += arr[i];
	}
	printf("\nsum of all elelments: %d\n",sum);

	return 0;
}
