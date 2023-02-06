/* program to use stat system call */
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main(int argc, char *argv[])
{
	struct stat var;

	if(argc < 2)
	{
		printf("not enough arguements\n");
		exit(1);
	}

	stat(argv[1],&var);
	
	printf("-----------struct stat members data------------------------\n");
	printf("Device: %lu\n",var.st_dev);
	printf("File Serial number: %lu\n",var.st_ino);
	printf("File mode: %lu\n",var.st_mode);
	printf("Link count: %lu\n",var.st_nlink);
	printf("size of file in bytes: %u\n",var.st_size);
	printf("Optimal block size for I/O: %d\n",var.st_blksize);
	printf("no. of 512 byte blocks allocated: %d\n",var.st_blocks);

}
