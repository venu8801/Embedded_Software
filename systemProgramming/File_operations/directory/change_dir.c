/* program to change directory using chdir() system call */
#include<stdio_ext.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
	int ret;
	ret = chdir("..");
	if(ret < 0)
	{
		printf("failed to change the directory\n");
		exit(1);
	}
	printf("directory changed\n");

}
