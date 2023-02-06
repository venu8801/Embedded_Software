/* program to understand write() system call */

/* write system call is used to write something on to a file 
 * as we write data into file the cursor f_cursor which is member of file object 
 * gets changed 
 * write system call's first input is fd no. so this system call must be used after 
 * the open system call as it returns the fd no. */
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
	int fd, ret;

	fd = open("./random.txt", O_RDWR); // if we change macro to RDONLY then whatever we
					   // write wont be reflected to file	

	printf("fd : %d\n",fd);
	if(fd < 0)
	{
		printf("failed to open file\n");
		exit(1);
	}
	
	char src_buff[100];
	printf("enter the string to write to the file: ");
	scanf("%[^\n]",src_buff);
	ret = write(fd, src_buff, strlen(src_buff));
	printf("no. of characters written: %d\n", ret);




}

P