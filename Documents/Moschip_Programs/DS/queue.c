/* implementing queue using arrays*/
void display(int *ptr);
void ascending(int *ptr);
void descending(int *ptr);
void delete(void);
void insert(int *ptr, int element);
#define SIZE 5
#include<stdio.h>
#include<stdlib.h>
int r = -1, f = -1;		 // global variables for front and rear index
void main()
{
	int option,s_element,p_element;
	int arr[SIZE];
	while(1)
	{
		printf("------------------\n");
		printf("select any option\n");
		printf("0.exit\n1.insert\n2.delete\n3.display\n4.ascending\n5.descending\n");
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
			case 4:
				printf("------------------\n");
				printf("you have selected ascending\n");
				ascending(arr);
				break;
	       		case 5:
				printf("------------------\n");
				printf("you have selected descending\n");
				descending(arr);
				break;
							
			default:
				printf("Invalid option selected\n");
		}
	}


}





// function for inserting into queue
void insert(int *ptr, int num)
{
	if(f == -1) 	// first time filling queue so incrementing r and f to point first element
	{
		r++, f++;
	}
	else if( (r == SIZE -1) && (f == 0)  || (r == f-1) )  // checking ig r is pointing last element and f is pointing 1st element
		// also checking whether r is pointing element before f *(in case of circular queue) 
	{
		printf("Queue is full\n");
		return;
	}

	else if(r == SIZE - 1)  // if above case fails then it means that queue not full there are some spaces
	{
		r = 0;  // resetting index of r to point that new element to be added
		ptr[r] = num; // adding that element to new space
		return;
	}
	else
	{
		r++;  //if above all cases failed, that means queue is either first time adding element or r is less than size of queue
	}

	ptr[r] = num;   // if any of the above non returning case passes means it should add the element to queue
}




void delete(void)
{
	if(f == -1)  // if f = -1 then that means there are no elements in queue
	{
		printf("Queue is empty\n");
		return;
	}

	else if(f == r)  // f = r that means there is only element in queue or we can say both r and f are pointing to same element
	{
		f = r = -1;

		return;
	}

	else if(f == SIZE-1) // if above cases fail but f points to last element means there are still elements in queue it should 
		// -point those elements *(circular queue case)
	{
		f = 0; // so to point those f should become 0
		return;
	}

	f++;  // above all returnig cases if those fail then that means we have elements in b/w 0 to 4 indices *(normal case)

}


void display(int *ptr)
{
	int i;

	if(f == -1)
	{
		printf("Queue is empty\n");
		return;
	}
	if( f <= r) // printing elements from f to r *(normal case)
	{
		for( i = f; i <= r; i++)
		{
			printf("%d\t",ptr[i]);
		}
	}
	else if(r < f)  // printing elements from r to f in *(circular queue case)
	{

		for( i = f; i < SIZE -1; i++)
		{
			printf("%d\t",ptr[i]);
		}

		for( i = 0; i <= r; i++)
		{
			printf("%d\t",ptr[i]);
		}

	}
}
/*void ascending(int *ptr)
{
	int i, j,temp;

	for(i = 0; i < SIZE; i++)
	{
		for(j = i + 1; j < SIZE ; j++)
		{
			if(ptr[i] > ptr[j])
			{
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
		//printf("%d\t",ptr[i]);
	}

}*/
void ascending(int *ptr)
{
	if(f == -1)
	{
		printf("There are no elements to ascend\n");
	}
	else
	{
		if(f <= r)
		{
			

void descending(int *ptr)
{
	int i, j,temp;

	for(i = 0; i < SIZE; i++)
	{
		for(j = i + 1; j < SIZE ; j++)
		{
			if(ptr[i] < ptr[j])
			{
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
		//printf("%d\t",ptr[i]);
	}

}






