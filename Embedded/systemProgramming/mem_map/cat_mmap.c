/* implementing cat command using mmap() calls */
#include<stdio.h>
#include<unistd.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
void main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("too less arguements\n");
		exit(1);
	}
	int fd, ret;

	struct stat buf;
	fd = open(argv[1], O_RDWR);
	if(fd < 0)
	{
		printf("failed to open %s\n",argv[1]);
		exit(1);
	}
	fstat(fd , &buf);
	char *ptr;
	ptr = mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0 );
	if(ptr == NULL)
	{
		printf("failed to map file to the memory\n");
		exit(1);
	}
	
	write(1, ptr, buf.st_size);

	munmap(ptr, buf.st_size);
	


}
