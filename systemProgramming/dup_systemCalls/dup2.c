/* program to understand dup2() system call */
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
void main()
{
	short int fd, ret;
	fd = open("orange.txt", O_CREAT | O_RDWR, 0600);
	if(fd <  0)
	{
		printf("failed ot open or create file\n");
		exit(1);
	}
	//the above lines create or open file depending upon
	//existence of the fle
	
	//duplicating opened file entry into /dev/stdout entry in fd table
	
	int dup2_fd = dup2( fd , 1 );
	if(dup2_fd < 0)
	{
		printf("failed to duplicate given fd entry\n");
		exit(1);
	}

	//we are closing stdout (fd = 1) device file
	//and duplicating fd value (i.e orange.txt) file into 
	// standard I/O stdout 
	//
	
	//as printf or puts use write sys call with fd entry 1 to print
	//something on screen but now in place of stdout at fd = 1
	//now the orange.txt file is located
	//whatever the string passed to printf() function will be 
	//written to the file
	//
	//
	
	printf("moschip technologies\n");

	puts("how are you\n");





}
