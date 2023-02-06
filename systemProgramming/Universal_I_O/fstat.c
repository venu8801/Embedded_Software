
/* program to use stat system call */
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
void main(int argc, char *argv[])
{
	struct stat var;

	if(argc < 2)
	{
		printf("not enough arguements\n");
		exit(1);
	}
	int fd = open(argv[1], O_RDONLY );
	if(fd < 0)
	{
		printf("failed to open file %s\n",fd);
		exit(1);
	}
	fstat(fd,&var);
	
	printf("-----------struct stat members data------------------------\n");
	printf("Device: %lu\n",var.st_dev);
	printf("File Serial number: %lu\n",var.st_ino);
	printf( "File mode: %lu\n",var.st_mode);
	//printf("Load\n");
	printf((var.st_mode & S_IXUSR)?"x":"--");
	printf((var.st_mode & S_IRUSR)?"r":"--");
	printf("Link count: %lu\n",var.st_nlink);
	printf("size of file in bytes: %u\n",var.st_size);
	printf("Optimal block size for I/O: %d\n",var.st_blksize);
	printf("no. of 512 byte blocks allocated: %d\n",var.st_blocks);
	printf("time of last access: %ld\n",var.st_atime);

}
