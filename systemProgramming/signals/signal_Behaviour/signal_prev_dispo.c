/* program to find return value of signal() system call*/
#include<signal.h>
#include<unistd.h>
#include<stdio_ext.h>
void my_handler(int signum)
{
	printf("signal recieved: %d\n",signum);



}
void my_handler2(int signum)
{
	printf("[2] signal recieved: %d\n",signum);


}
void main()
{
	int i = 0;

	pid_t pid = getpid();
	printf("pid: %lu\n",pid);

	int *ret = signal(SIGINT, my_handler);
	printf("myhandler: %p\n", my_handler);
	printf("default: %d\n",SIG_DFL);
	printf("ret : %p\n",ret);
	
	int *ptr = signal(SIGINT, my_handler2);
	printf("[2] ret: %p\n",ptr);
	


	while(i <= 30)
	{
		sleep(1);
		printf("i = %d\n",i);
		i++;
	}
	



}
