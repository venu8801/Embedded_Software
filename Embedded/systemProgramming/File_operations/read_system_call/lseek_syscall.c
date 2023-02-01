/* lseek system call */

/* lseek system call is used to changed the f_cursor inside file object of opened file
 * on success this call will return new offset value and on failure it will return -1*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

void main()
{

	int fd, ret;
	char buff[4096];
	fd = open("./random.txt", O_RDWR | O_CREAT);

	if(fd < 0)
	{
		printf("failed to open file\n");
		exit(1);
	}
	ret = lseek(fd, 4, SEEK_SET);
	if(ret < 0)
	{
		printf("failed to seek into file");
		exit(1);
	}
	printf("return from seek f_cursor = %d\n",ret);
	printf("enter the string to write to file: " );
	scanf("%[^\n]",buff);
	ret = write(fd, buff, strlen(buff));
	printf("return from ret: %d\n", ret);

}
