
//usage of sytem call
//
//this is a program to understand vfork system call
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int x = 10;

void main()
{
	pid_t pid;
	printf("before calling\n");
	printf("X addr: %p         %d\n",&x, x);
	pid = vfork();
	if(pid < 0)
	{
		printf("failed to create process\n");
		exit(2);
	}
	if(pid > 0)
	{
		

		printf("X addr: %p         %d\n",&x, x);
		printf("parent: %p         %d\n",&x,x);
		exit(0);
	}
	else
	{
		sleep(5);
		x = 23;
		printf("child: %p         %d\n",&x,x);
		exit(0);
	}
}

		

