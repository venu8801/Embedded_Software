//this is a program to understand copy on write technique
#include<stdio.h>
#include<unistd.h>
int x = 10;

void main()
{
	pid_t pid;
	printf("X addr: %p         %d\n",&x, x);
	pid = fork();
	if(pid < 0)
	{
		printf("failed to create process\n");
		exit(2);
	}
	if(pid > 0)
	{
		
		printf("X addr: %p         %d\n",&x, x);
		x = 20;
		printf("parent: %p         %d\n",&x,x);
		exit(0);
	}
	else
	{
		sleep(5);
		printf("child: %p         %d\n",&x,x);
		exit(0);
	}
}

		

