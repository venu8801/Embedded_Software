
void display(int *ptr);
void search(int *ptr, int element);
void pop(void);
void push(int *ptr, int element);
#include<stdio.h>
#include<stdlib.h>
#define N 5
int i = -1;
void main()
{
	int option,s_element,p_element;
	int arr[N];
	while(1)
	{
				printf("------------------\n");
		printf("select any option\n");
		printf("0.exit\n1.push\n2.pop\n3.display\n4.search\n");
		scanf("%d",&option);
		switch(option)
		{
			case 0:
				printf("you have selected exit\n");
				exit(0);
			case 1:
				printf("------------------\n");
				printf("you have selected push\n");
				printf("enter the element you want to push: ");
				scanf("%d",&p_element);
				push(arr,p_element);
				break;
			case 2:
				printf("------------------\n");
				printf("you have selected pop\n");
				pop();
				break;
			case 3:
				printf("------------------\n");
				printf("you have selected display\n");
				display(arr);
				break;
			case 4:
				printf("------------------\n");
				printf("you have selected search\n");
				printf("enter the element you want to search: ");
				scanf("%d",&s_element);
				search(arr, s_element);
				break;
			default:
				printf("Invalid option selected\n");
				exit(0);
		}
				printf("------------------\n");
	}
}









void push(int *ptr, int element)
{
	if(i <= 3)
	{
		i++;
		ptr[i] = element;
	}
	else
		printf("stack is full\npop any element\n");
}

void pop(void)
{
	if(i == -1)
		printf("Stack is empty\n");
	else{
		i--;
	printf("element popped\n");
	}
}

void search(int *ptr, int element)
{
	int j;

	for(j = 0; j <= i; j++)
	{
		if(ptr[j] == element)
			printf("element found at index: %d\n",j);
	}
}
void display(int *ptr)
{
	int j;
	for(j = 0; j <= i; j++)
	{
		printf("%d\t",ptr[j]);
	}
	printf("\n");
}

