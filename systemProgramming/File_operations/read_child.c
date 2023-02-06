/* read system call on child process where parent process had opened two files
 * before creating child process */

/* child process inherits the FD table from the parent */
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
	int fd, ret;

	fd = open("./hello.txt", O_RDONLY);
	if(fd < 0)
	{
		printf("failed to open file\n");
		exit(1);

	}

	printf("from parent->  fd : %d\n",fd);
	

	//creating child process
	
	pid_t pid;

	pid = fork();

	if(pid < 0)
	{
		printf("failed to create child process\n");
		exit(1);
	}
	else if(pid > 0)
	{
		printf("from parent: child pid = %d\n",pid);
		exit(1);
	}
	else
	{
		// child inherits the copy of fd table from parent
		printf("from child: child pid: %d\n",getpid());
		int fd2 = open("hello.txt",O_RDONLY);
		if(fd2 < 0)
		{
			printf("failed to open file from child\n");
			exit(2);
		}
		printf("from child-> fd2: %d\n",fd2);
		int i ;
		for(i = 0; i < 120; i++)
		{
			printf("i = %d\n",i);
			sleep(1);
		}


	}



}
