#include<stdio.h>
#include<unistd.h>
void main()
{
	pid_t pid, ppid;
	pid = getpid();
	ppid = getppid();
	printf("Process ID: %d\n",pid);
	printf("Parent Process ID: %d\n",ppid);
	scanf("%d",&pid);
	while(1);
}
