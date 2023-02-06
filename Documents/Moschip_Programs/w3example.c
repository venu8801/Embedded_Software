#include<stdio.h>
#include<math.h>
void main()
{
	int seconds;

	printf("enter no. of seconds:");

	scanf("%d",&seconds);

	int hours = seconds / 3600;
	

	int mins = ((float)seconds/(float)60 - (hours*60));

	
	float secs = ((float)seconds/(float)60 - seconds/60) * 60;

	




	printf("H:%d M:%d S:%d\n",hours, mins,floor( secs));
}
