
/* program to remove a directory using rmdir system call */
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
void main()
{
	int ret;

	ret = rmdir("sample");
	if(ret < 0)
	{
		printf("failed to remove a directory\n");
		exit(1);
	}
	else
		printf("directory removed\n");
}
