#include<stdlib.h>
#include<stdio.h>
void main()
{
	int *ptr = calloc(1,1024*1024*1024);

	if(ptr == NULL){
		printf("falied to allocate\n");

		exit(1);

	}
	
	printf("address: %p\n",ptr);
	*ptr = 56;
	
	printf("%d\n",*ptr);
	scanf("%d",ptr);
}

