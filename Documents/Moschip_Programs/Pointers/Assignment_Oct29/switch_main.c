#include<stdio.h>
#include"assignment.h"
#include<stdlib.h>
#include<stdio_ext.h>
#define N 5

void main()
{
	int option, ret; // option and function return variable

	int *ptr;

	ptr = (int *) malloc( N * sizeof(int));

	if(ptr == NULL)
	{
		printf("Failed to allocate memory in heap\n");
		exit(1);

	}

	printf("start address of DM: %p\n",ptr);

	while(1)
	{
		printf("Select any option\n");
		printf("0.Exit\n1.Read Inputs\n2.Display Inputs\n3.Binary\n4.Biggest among all\n5.2nd highest\n6.ascending order\n");
		__fpurge(stdin);
		scanf("%d",&option);


		switch(option)
		{
			case 0:
			printf("---------------------\n");
				printf("\n");
			       printf("Invalid Input\n");
		       		exit(0);
		 	case 1:
		 		printf("---------------------\n");
				printf("\n");
				printf("selected option: %d\n",option);		
				read(ptr, N);
				break;
			case 2:printf("---------------------\n");
				printf("\n");
				printf("selected option: %d\n",option);				
				display(ptr, N);
				break;
			case 3:printf("---------------------\n");
				printf("\n");
				printf("selected option: %d\n",option);		
				decimal_binary(ptr, N);
				break;
			case 4:printf("---------------------\n");
				printf("\n");
				printf("selected option: %d\n",option);		
				ret = biggest(ptr, N);
				printf("biggest num: %d\n",ret);
				break;
			case 5:printf("---------------------\n");
				printf("\n");
				printf("selected option: %d\n",option);		
				SecondHighest(ptr,N);
				break;
			case 6:printf("---------------------\n");
				printf("\n");
				
				printf("selected option: %d\n",option);		
				Ascending_Order(ptr, N);
				break;
		}
		printf("---------------------\n");
		printf("\n");
	}// while termination
}
