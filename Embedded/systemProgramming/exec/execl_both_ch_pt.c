

/* replacing child and parent process image with a new process that is calcutor and calender*/
/* ps lies in /bin directory 
 * declaration of execl();
 * int execl(const char *path, const char *arg0,...,(char *)0);
 */

#include<unistd.h>
#include<stdio.h>
void main()
{
	pid_t pid, cpid;


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
		printf("parent image replaced\n");
		printf("from parent --child PID: %d\n",pid);
		execl("/bin/gnome-calendar", 0);
	


	}
	else
	{
	//replacing child process image of a.out wiht gnome-calculator
		sleep(15);
		printf("child image replaced\n");
		execl("/bin/gnome-calculator", 0);


	}

}


	
	


