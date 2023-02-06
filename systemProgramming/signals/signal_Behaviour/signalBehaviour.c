/* checking signal behaviour using SIG_IGN */

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void main()
{
	int i = 0;
	printf("process id: %d\n",getpid());

	signal(SIGINT, SIG_IGN);  // ignores SIGINT signal 
	signal(SIGABRT, SIG_DFL);  // the behaviour is set to default for SIGINT signal 
	

	while(1)
	{
		printf("i : %d\n", i);
		sleep(1);
		i++;
	}
}
