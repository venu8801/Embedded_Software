//wait system call
//this sytem call suspends parent process until its child process terminates
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
	pid_t pid, cpid;
	int stat = 0, i = 0;
	pid = fork();
	
	if(pid < 0 )
	{	
		printf("failed to create child process\n");
		exit(2);

	}
	else if(pid > 0)
	{	
		sleep(30);	
		printf("Parent: child->pid: %d\n",pid);
		cpid = waitpid(pid,&stat,WUNTRACED|WCONTINUED);
		
		//printf("status received: %d\n", stat);
		//sleep(5);
		//printf("Parent: child->pid: %d\n",cpid);
		if(WIFSTOPPED(stat))
		{
			printf("process STOPPED\n");
			printf("------>%d \n",WSTOPSIG(stat));

		

		}
	/*	if(WIFSIGNALED(stat))
		{
			printf("--->%d\n",WTERMSIG(stat));
		}
		//if(WCOREDUMP(stat))*/
		exit(0);
	}
	else
	{
		//sleep(5);	
		//child process
		while(i <= 30)
		{
			sleep(1);
			printf("%d\n", i);
			i++;

		}	
		exit(25);
	}

	
}
