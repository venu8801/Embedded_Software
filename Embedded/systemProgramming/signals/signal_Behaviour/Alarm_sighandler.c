/* modifying the behaviour of the SIGALRM signal */
#include<stdio.h>

#include<unistd.h>
#include<signal.h>
void alarm_handler(int signo);

void main()
{
	printf("process id: %d\n",getpid());
	int i = 0;
	alarm(2);

	signal(SIGALRM, alarm_handler);

	while(1)
	{
		printf("i : %d\n", i);
		sleep(1);
		i++;
		printf("going to sleep\n");
		sleep(2);
		printf("woke up\n");
		alarm(2);

	}

}
void alarm_handler(int signo)
{
	printf("signal recieved: %d\n", signo);
}
