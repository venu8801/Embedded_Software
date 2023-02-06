/* dup sytem call */
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
	int dupFD = dup(1);//duplicating /dev/stdout
	printf("dupFD: %d\n",dupFD); //printing value returned by dup
	
	
	int ret = close(1); //closing stdout
	//after closing 1 we cant see any outputs on screen

	int fd;
	/* dup system call is used to duplicate fd table entry to other 
	 * fd table location */
	fd = open("hello.txt", O_CREAT, 0664); //creating a file hello.txt
	if(fd < 0)
	{
		printf("failed to create file\n");
		exit(1);
	}
	write(dupFD, "moschip technologies\n", strlen("moschip technologies\n"));
	// now dupFD at fd3 points to /dev/stdout so write with dupFD will print 
	// on screen
	printf("fd: %d\n", fd); // now the fd returned by 
	//if 


}
