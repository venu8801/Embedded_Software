/* when we open same file using calling multiple open calls*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
void main()
{
	int fd1, fd2, fd3;

	fd1 = open("hello.txt", O_RDONLY);
	fd2 = open("hello.txt", O_RDONLY);
	printf("fd1:%d and fd2:%d\n",fd1,fd2);
	close(fd1);
	fd3 = open("/home/venus/Downloads/int_op.c", O_RDONLY);
	printf("fd3:%d\n",fd3);
	
	
}
