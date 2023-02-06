/* program to understand read system call */


/* read system call on success return no. of bytes read from the file 
 * on failure returns -1 
 * read system call needs fd no. and buffer address and size of buffer as inputs
 * we cannot use read() system call without using open system call */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void main()
{
	int fd; // file descriptor num
	int ret; // to store return value of read system call
	char buffer[5]; // buffer of 5 bytes which can store 5 characters including null

	fd = open("/home/engineer/venu/systemProgramming/File_operations/hello.txt", O_RDONLY);

	if(fd < 0)
	{
		/* read system call failed */
		printf("failed to open from the file\n");
		exit(1);
	}

	printf("file descriptor no: %d\n", fd);
	
	printf("close return: %d\n",close(fd));

	ret = read(0, buffer, 4 ); // we have given buffer size of 4 because the last byte 
				    // is for storing null character
	printf("return from read: %d\n",ret);
	if(ret < 0)
	{
		printf("failed to read from file\n");
		exit(1);
	}
	
	printf("content in file\n");
	printf("%s\n",buffer);

}

