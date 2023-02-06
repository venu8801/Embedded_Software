
#include<stdio.h>
int main()
{
	int size,arr[size];
	printf("Enter size of array: ");
	scanf("%d",&size);
	for(int i = 0; i < size; i++){
			scanf("%d",&arr[i]);
	}
		printf("Entered array: {  ");
	for(int i = 0; i < size; i++){
			printf("%d",arr[i]);
	}
		printf("}  ");
}
