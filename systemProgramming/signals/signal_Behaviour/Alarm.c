/* program to understand alarm system call */
#include<stdio.h>
#include<unistd.h>
void main()
{
	printf(" process ID: %d\n",getpid());
	int i = 0;
	// alarm takes input in seconds 
	//
	alarm(5);  //timer for 5 seconds has been set 
		   //after 5 seconds kernel will send a signal to the process
	//here execution wont stop
	

	/* alarm() is not a blocking call*/

	while(i <= 10)
	{
		printf("i : %d\n",i);
		sleep(1);
		i++;

	}

	/* default behaviour of the SIGALRM is to terminate the process */
	/* the default behaviour can be changed using signal() sys call */

}
