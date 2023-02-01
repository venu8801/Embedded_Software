/* program to implement copy command using memory map calls
 * */
#include<stdio.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
void main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("too less arguements\n");
		exit(1);
	}
	char *ptr, *d_ptr;
	int fd, fd1;
	struct stat file_buff;

	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		printf("failed to open file %s \n",argv[1]);
		exit(2);
	}
	fstat(fd, &file_buff);

	ptr = mmap(NULL, file_buff.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if(ptr == NULL)
	{
		printf("failed to map file\n");
		exit(1);
	}
	// trying to open destination file
	/*  fd1 = open(argv[2], O_RDWR);
	if(fd1 < 0)
	{
		fd1 = open(argv[2], O_CREAT , 0664);
		if(fd < 0)
		{
			printf("failed to create file\n");
			exit(2);
		}
		else
			printf("file created -\n");
	} 	*/
	fd1 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0664);
	if(fd1 < 0)
	{
		printf("failed to create file\n");
		exit(2);
	}
	
	//truncating destination file
		printf("source file size: %lu\n",file_buff.st_size);
	int ret = ftruncate(fd1, file_buff.st_size);
	 //int ret = truncate(argv[2], file_buff.st_size);
	if(ret < 0)
	{
		printf("failed to truncate file\n");
		exit(1);
	}  
	d_ptr = mmap(NULL,file_buff.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd1, 0 );
	if(d_ptr == NULL)
	{
		printf("failed to destination file\n");
		exit(4);
	}
	printf("source file size: %lu\n",file_buff.st_size);
	if(d_ptr == memcpy( d_ptr, ptr, file_buff.st_size))
		printf("copied file to %s\n",argv[2]);
	

}
