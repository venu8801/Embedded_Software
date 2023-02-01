// program to create a process from a parent process using fork system call
#include<stdio.h>

#include<unistd.h> // library for sytem calls
#include<sys/types.h> // library for typedefs

void main()
{
	pid_t pid;
	int i =0;
	int n;
	pid = fork();  //returns newly created processes id on success
	if(pid<0)
	{
		printf("failed to create new process\n");
		exit(1);
	}

	if(pid > 0)
	{
		scanf("%d",&n);

		printf("from Parent: %d \n",getpid());
		printf("Created Child Process:%d \n", pid);
		printf("n: %d\n",n);
	
	//	sleep(10);
		//while(i<=300)
		while(1)
		{
			sleep(2);
			//
			printf("parent:%d\n",i);
			i++;
		}
		exit(0);
	}
	else
	{	
		printf("child process \n");
		scanf("%d",&n);
		printf("--------------------------\n");
		printf("from child: %d\n",getpid() );
		printf("Child: %d\n",getpid());
		printf("child process's fork return value: %d\n",pid);
		printf("n: %d\n",n);
		sleep(10);
	//	while(i<=500)
		while(1)
		{

			sleep(2);
			printf("child:%d\n",i);
			i++;
		}
		exit(0);
		

	}

	
}
