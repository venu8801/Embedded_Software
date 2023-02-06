/* program to understand signal set var */


/* sigprocmask() system call */
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void main()
{
	int i = 0;
	printf(" process id: %d\n", getpid());
	sigset_t signalSet;

	sigemptyset(&signalSet); // empties the signalSet variable
				 //
	printf(" signal Set var: 0x%x\n", signalSet);

	sigaddset(&signalSet, 2); // adding SIGINT signal to the signalSet var
	
	sigprocmask(SIG_BLOCK, &signalSet, NULL); // this changes the actual kernel syscall

	//printf(" signal Set var after setting: 0x%x\n", sigprocmask(0, NULL, &signalSet));


	while(i < 100)
	{
		sleep(1);
		printf(" i = %d\n", i);
		i++;
	}


}

