/* program to create directory using mkdir system call */
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
void main()
{
	int ret;

	ret = mkdir("sample", 0664);
	if(ret < 0)
	{
		printf("failed to crate a directory\n");
		exit(1);
	}
	else
		printf("directory created\n");
}
