/* program to establish two way communication on both server and client side using named pipes */
#include<stdio.h>
#include<unistd.h>
#include<stdio_ext.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
void main()
{

	//while(1)

	int fd, ret;

	char wbuff[1000], rbuff[1000];

	while(1)
	{

	fd = open("sfifo", O_RDONLY);
	if(fd < 0)
	{
		ret = mkfifo("sfifo", 0664);
		if(ret < 0)
		{
			printf("failed to create fifo\n");
			exit(1);
		}
		fd = open("sfifo", O_RDONLY);
		if(fd < 0)
		{
			printf("failed to read fifo\n");
			exit(2);
		}


	}
	ret = read(fd, rbuff, 1000);
	if(ret < 0)
	{
		printf("failed to read from fifo\n");
		exit(1);

	}
	int i;
	for(i= 0; rbuff[i] != '\0'; i++)
	{
		if( (rbuff[i] >= 'a') && (rbuff[i] <= 'z') )
			rbuff[i] -= 32;
		else if( (rbuff[i] >= 'A') && (rbuff[i] <= 'Z') )
			rbuff[i] += 32;
	}
	write(1, rbuff, ret);
	



	close(fd);
	
	printf("\n[s] enter string: ");
	__fpurge(stdin);
	scanf("%[^\n]", wbuff);
	if(strcmp("exit",wbuff) == 0)
		exit(0);
	fd = open("cfifo", O_WRONLY);
	if(fd < 0)
	{
		printf("failed to open\n");
		exit(1);

	}
	ret = write(fd, wbuff, strlen(wbuff));
	if(ret < 0)
	{
		printf("failed to write\n");
		exit(3);
	}
	close(fd);
	}
	
}
