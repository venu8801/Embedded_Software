#include<stdio.h>
#include<limits.h>
int main()
{
	unsigned long int num = ULONG_MAX, count ;
	   


	while(num > 0) {
		num = num / 10;
		count += 1;
	}

	printf("\n count : %d",count);
	
	return 0;
}
