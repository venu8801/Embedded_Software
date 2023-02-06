

void display(int *ptr);
void search(int *ptr, int element);
void delete(void);
void insert(int *ptr, int element);
#include<stdio.h>
#include<stdlib.h>
#define N 5
int findex = -1, r_index = -1 ;
void main()
{
	int option,s_element,p_element;
	int arr[N];
	while(1)
	{
		printf("------------------\n");
		printf("select any option\n");
		printf("0.exit\n1.insert\n2.delete\n3.display\n4.search\n");
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
				insert(arr,p_element);
				break;
			case 2:
				printf("------------------\n");
				printf("you have selected pop\n");
				delete();
				break;
			case 3:
				printf("------------------\n");
				printf("you have selected display\n");
				display(arr);
				break;
				/*case 4:
				  printf("------------------\n");
				  printf("you have selected search\n");
				  printf("enter the element you want to search: ");
				  scanf("%d",&s_element);
				//search(arr, s_element);
				break;                 */
			default:
				printf("Invalid option selected\n");
		}
	}


}


void insert(int *ptr, int element)
{
	if(r_index == N - 1) //checking if queue is full or not
	{
		printf("queue is full \n");
		return;
	}

	if( findex == -1 && r_index == -1) // checking if rear index and front index are same or not
	{

		findex++;
		r_index++;

		ptr[r_index] = element;

	}
	else
	{
		r_index++;
		ptr[r_index] = element;
	}

}




void delete(void)
{
	if(findex == r_index)//
	{
		// resetting both to -1
		findex = r_index = -1;
		return;
	}
	printf("\"first\" element out\n");
	findex++;

}


void display(int *ptr)
{
	int j;
	if(findex == -1 || r_index == -1)
	{
		printf("\"stack is empty\"\n");
	}
	else{
		//	printf("%d--%d\n",findex,ptr[findex]);
		for(j = findex; j <= r_index; j++)
		{
			printf("%d\t",ptr[j]);
		}
		printf("\n");
	}
}


