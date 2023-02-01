#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void myhandler(int signalno)
{
	printf("signal - %d\n",signalno);
	printf("my handler is invoked\n");
}

void main()
{
	
	int i=0;
	
	//int sigosset;
	
	size_t oset;
	
	struct sigaction act;
	
	act.sa_handler = myhandler;
	
	act.sa_flags = 0;
	
	// printing the status of oset before setting the value
	
	sigprocmask(0, NULL, &oset);
	
	printf("sigoset: 0x%x\n", oset);


	
	//adding the set now
	
	sigemptyset(&act.sa_mask);
	
	sigaddset(&act.sa_mask,14);
	
	sigaddset(&act.sa_mask,2);
	
	sigaddset(&act.sa_mask,6);

	sigprocmask(SIG_BLOCK,&act.sa_mask,NULL);
	
	sigprocmask(0, NULL, &oset); // to find the status of current signal mask in pcb of kernel space
	
	printf("sigoset: 0x%x\n", oset);
	
	sigaddset(&act.sa_mask, 18); // blocking 18th signal
	
	sigprocmask(SIG_BLOCK, &act.sa_mask, &oset);


	printf("sigoset: 0x%x\n", oset);
	
	sigprocmask(0, NULL, &oset); // to find the status of current signal mask in pcb of kernel space
	
	printf("sigoset: 0x%x\n", oset);
	
	sigaction(2,&act,NULL);
	
	while(i<=10)
	{
	
		sleep(1);
	
		printf("pid : %d,i= %d\n",getpid(),i);
	
		i++;
	
	}
	
	sigdelset(&act.sa_mask,14);
	
	sigprocmask(SIG_UNBLOCK,&act.sa_mask,NULL);
	
	//alarm(3);
	
	sleep(4);
	
	i=0;
	
	while(i<=10)
	
	{
	
		sleep(1);
	
		printf("pid : %d,i= %d\n",getpid(),i);
	
		i++;
	
	}


	
	sigprocmask(0, NULL, &oset); // to find the status of current signal mask in pcb of kernel space
	

	
	printf("sigoset: 0x%x\n", oset);

}


