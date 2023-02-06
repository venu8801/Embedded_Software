/* client side code for named pipes */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
void main()
{
	int ret, fd;


	char wbuff[1000] = "request" ;

	fd = open("s_fifo", O_WRONLY); /* trying to open file if it already exists */
	if(fd < 0)
	{
		printf("failed to open file\n");
		exit(1);


	}

	// writing to rbuff
	ret  = write(fd, wbuff, 100);
	close(fd);


}




