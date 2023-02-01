#include<stdio.h>
#include<unistd.h>
void main()
{
	int y;
	fork();
	fork();
	fork();
	fork();
	printf("#--hello--#\n");
	scanf("%d",&y);
}
