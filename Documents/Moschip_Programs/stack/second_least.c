#include<stdio.h>
#include<limits.h>
void main()
{
	int i;
	int arr[6] = {5,0,3,0,0,0};

	int min = INT_MAX;

	int s_min = INT_MAX;

	for(i = 0; i < 6; i++) // first finding out least value
	{
		if(arr[i] == arr[i+1])
			continue;
		
			if(arr[i] < min)
			{
				s_min = min;
				min = arr[i];
			}
			else if(arr[i] < s_min)
			{
				s_min = arr[i];
			}
		
	}
	printf(" least element: %d\n",min);
	/*	for(i = 0; i < 6; i++)
		{


		if(arr[i] < s_min  &&  arr[i] != min)
		s_min = arr[i];

		}*/
	printf("second least element: %d\n",s_min);

}	

