/* client side code */
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio_ext.h>
void main()
{
	while(1)
	{

	int fd, ret;

	char wbuff[1000], rbuff[1000];
	
	
	/* writes into sfifo first */
	
	fd = open("sfifo", O_WRONLY);
	if(fd < 0)
	{
		printf("failed to open\n");
		exit(1);

	}
	__fpurge(stdin);
	printf("\n[c] enter string: ");
	scanf("%[^\n]", wbuff);
	if(strcmp("exit",wbuff) == 0)
		exit(0);
	ret = write(fd, wbuff, strlen(wbuff));
	if(ret < 0)
	{
		printf("failed to write\n");
		exit(3);
	}
	close(fd);

	
	/* reads from cfifo */
	fd = open("cfifo", O_RDONLY);
	if(fd < 0)
	{
		ret = mkfifo("cfifo", 0664);
		if(ret < 0)
		{
			printf("failed to create fifo\n");
			exit(1);
		}
		fd = open("cfifo", O_RDONLY);
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
	}
	
}
