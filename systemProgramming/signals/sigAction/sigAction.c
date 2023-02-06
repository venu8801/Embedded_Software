/* program to change behaviour of a signal using sigaction() sys call
 * sigaction uses pre-defined structure called struct sigaction()
 */
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void sig_int_handler(int sig);
void main()
{
	printf("process id: %d\n", getpid());
	struct sigaction act;

	act.sa_handler = sig_int_handler; //installing my handler function 
	
	act.sa_flags = 0;

	sigemptyset(&act.sa_mask); // emptying signal set variable
				   //
	

	sigaddset(&act.sa_mask, SIGABRT); //adding SIGABRT to the block
	sigprocmask(SIG_BLOCK, &act.sa_mask,0);
	
	size_t sigoset;
	sigprocmask(0, NULL, &sigoset);

	printf("sigoset: %x\n",sigoset);

	sigaction(SIGINT, &act, 0); //changing the behaviour of a signal
				    //using sigaction

	int i = 0;
	while(i < 100)
	{
		printf("i = %d\n",i);
		i++;
		sleep(1);
	}
	
	sigdelset(&act.sa_mask, SIGABRT	); 


}
void sig_int_handler(int sig)
{
	printf("--from signal handler----\n");
	printf("signal recieved: %d\n", sig);
	//exit(1); //program exits here on recieving the signal
}



