/* wait pid system call */
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
{
	int stat;

	pid_t pid, cpid;

	/*waitpid() sys call acts as a blocking call based on 
	 * the option provided to it*/
	pid = fork();

	if(pid < 0)
	{
		printf("failed to create a child process\n");
		exit(1);
	}
	else if(pid > 0)  /*executes in parent process*/
	{
		printf("from parent--child process: %d\n",pid);
		cpid = waitpid(pid, )






}
