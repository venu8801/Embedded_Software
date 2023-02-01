#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void SigHandler(int);
void main()
{
	int i = 0;
	void (*fptr)(int);
	fptr = SigHandler;
	signal(SIGINT,SigHandler);
	while( i < 1000)
	{
		sleep(1);
		printf(" i : %d\n",i);
		i++;
	}



}


void SigHandler(int sig)
{	
	printf("signal recieved %d \n",sig );
	
}
