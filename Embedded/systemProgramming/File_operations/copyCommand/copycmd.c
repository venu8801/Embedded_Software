/*implementing copy command using open/creat system call */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
void main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("invalid arguements please use -h to know usage\n");
		exit(2);
	}
	if(argc <= 2)
	{
		if( (argv[1][0] == '-') && (argv[1][1] == 'h'))
		{
			printf("usage---\n");
			printf("copy   <source_filename_with_path>  <destination file name with path> ");
			exit(0);
		}
		printf("invalid arguements please use -h to know usage\n");
		exit(2);
	}
	int fd_src, fd_dest, ret, ret2;
	fd_src = open(argv[1], O_RDONLY);
	if(fd_src < 0)
	{
		printf("failed to open file\n");
		exit(1);
	}
	fd_dest = open(argv[2], O_RDWR | O_TRUNC | O_CREAT, 0664);
	if(fd_dest < 0)
	{
		printf("failed to open file\n");
		exit(1);
	}
	char buff[1024];
	
	while(ret = read(fd_src, buff, 1024))
	{
		printf("ret:%d\n",ret);
		ret2 = write(fd_dest, buff,ret);
		if(ret < 0 | ret2 < 0)
		{
			printf("failed to read/write to file\n");
			exit(3);
		}
		printf("--writing to %s\n--",argv[2]);
	}

	if(ret2 == 0)
	printf("file copied to %s successfully\n",argv[2]);



}
