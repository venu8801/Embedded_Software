/* program to establish communication between two non-related process 
 * only one way communication that is from server to client not a two way communication */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
void main()
{
	int ret, fd;


	char rbuf[1000];

	fd = open("s_fifo", 0660); /* trying to open file if it already exists */
	printf("server fd: %d\n",fd);
	if(fd < 0)
	{

		/* creating a fifo object using mkfifo() */
		ret = mkfifo("s_fifo", 0660);
		if(ret < 0)
		{
			printf("failed to create fifo object/file in cwd\n");
			exit(1);
		}

		fd = open("s_fifo", O_RDONLY);
		printf("server fd: %d\n",fd);
		if(fd < 0)
		{
			printf("failed to open fifo file\n");
			exit(1);
		}

	}

	// reading to rbuff
	ret  = read(fd, rbuf, 100);
	printf("server read ret: %d\n",ret);
	if(ret < 0)
	{
		printf("failed to read fifo\n");
		exit(3);
	}
	write(1, rbuf, ret);
	close(fd);


}




