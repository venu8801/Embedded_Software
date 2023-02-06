#include<stdio.h>
#include<pthread.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	pid_t pid;
	int ret,i,f;
	int fd[2];
	char buf[200] ;
	ret = pipe(fd);
	printf("return value is :%d\n",ret);
	pid = fork();
	if(pid < 0)
	{
		printf("failed to create new process\n");
		exit(0);
	}
	else if(pid>0)
	{
		printf("welcome parent\n");
		close(fd[0]);
		write(fd[1] , "vEnU iS a gOoD BoY", 19);
		exit(0);
	}
	else
	{
		printf("welcome child\n");
		close(fd[1]);
		ret = read(fd[0] , buf , 20);
		buf[ret] = '\0';
		f = strlen(buf);
		printf("string length is :%d\n",f);
		for(i=0 ; i<f ; i++)
		{
			printf("%c\n",buf[i]);
			if(buf[i] >= 'a' && buf[i] <= 'z' )
			
				buf[i] = buf[i]-32;
		}
		printf("read string is : %s\n",buf);
		exit(0);
	}
}
