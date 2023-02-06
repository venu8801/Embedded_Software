
/* replacing child process image only with a new process that is ps*/
/* ps lies in /bin directory 
 * declaration of execl();
 * int execl(const char *path, const char *arg0,...,(char *)0);
 */

#include<unistd.h>
#include<stdio.h>
void main()
{
	pid_t pid, cpid;
	int stat = 0;
	printf(" parent---processID: %d\n",getpid());

	sleep(10);

	//execl("/bin/ps", "ps", "ax", 0);
	pid = fork();
	if(pid < 0)
	{
		printf("failed to create child process\n");
		exit(1);
	}
	else if(pid > 0)
	{	/*executes this code in parent*/
		printf("from parent --child PID: %d\n",pid);
		cpid  = wait(&stat);
		printf(" child PID: %d terminated\n",cpid);
	


	}
	else
	{
	//replacing child process image of a.out wiht gnome-calculator
		sleep(15);
		execl("/bin/gnome-calculator", 0);


	}

}


	
	




