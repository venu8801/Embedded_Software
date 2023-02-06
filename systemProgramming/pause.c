/*  program about pause() syscall */
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void main()
{
	int i = 0;
	pause();
	while(i < 100)
	{
		printf("i : %d\n", i);
		i++;
		sleep(1);
	}
}
