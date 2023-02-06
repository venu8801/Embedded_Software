/* program to implement cat command*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
void help_menu()
{
	printf("---------cat clone------------\n");
	printf("usage--\n");
	printf("flag		description\n");
	printf("-h		help");
	printf("/path/of/file\n");
}
void main(int argc, char *argv[])
{
	if(argc <= 1)
	{
		printf("Invalid use of command\n");
		printf("use -h flag to know usage\n");
		exit(1);
	}
	//printf("%c",argv[1][0]);
	if(argv[1][0] == '-')
	{
		if(argv[1][1] == 'h')
		{

			help_menu();
			exit(0);
		}
		else
		{
			printf("invalid flag use -h to know\n");
			exit(2);
		}
	}

	int fdes, ret;
	char buff[8192]; // buffer of size 8 kilo  bytes
	fdes = open(argv[1], O_RDONLY);
	if(fdes < 0)
	{
		/* open systemcall failure*/
		printf("failed to open %s ", argv[1]);
		exit(1);
	}
	printf("file descriptor: %d\n",fdes);
	
	int count = 0;
/* this buffer is of 5 bytes is used only for storing 5 bytes from the text file and printing those 5 bytes again those 5 bytes are over-written */
	while(ret = read(fdes, buff, 8191))
	{
		if(ret < 0)
		{
			printf("failed to read from file\n");
			exit(1);
		}
		buff[ret] = '\0';
		printf("%s",buff);

	}
	/*while(ret = read(fdes, buff, 4))
	{
		if(ret < 0)
		{
			printf("failed to read frome %s file\n",argv[1]);
			exit(1);
		}
		printf("ret from read: %d\n",count);
		count += ret;
		
	}
	buff[count] = '\0';*/
/* this reads 8191 bytes from the  file so no loop is required if the file is less than this */
	
/*	ret = read(fdes, buff,8191 );   
	printf("data inside file\n");
	printf("%s\n",buff); */
	


}
