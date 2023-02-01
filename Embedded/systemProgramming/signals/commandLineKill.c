//program to kill a process using command line arguements
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{

	if( (argc <= 2) || (argv[1][0] != '-')) 
	{
			printf("not enough command line arguements\n");
			printf("use -h\n");
			exit(0);

	}
	pid_t pid;
	if(argv[1][0] != '-')
	{
		printf("invalide use please refer help by using -h flag\n");
		exit(0);
	}
	//converting the third command line arguement from string to integer
	if(argv[2][0] =='-')
	{	
		printf("process id cannot be negative\n");
		exit(8);

	}
	int len = strlen(argv[2]);
	int i = 0;
	int p = 1;
	int num = 0, digit = 0;
	for(i = 0; i < len; i++)
	{
		if( (argv[2][i] >= 48) && (argv[2][i] <= 57) )
		{
			digit = argv[2][i] - 48;
			num = num*10 + digit;
			

		}
	}
	printf("pid: %d\n",num);
	switch(argv[1][1])
	{	
		case 'k':
			printf("attempting to kill the process\n");
			int ret = kill(num, 9);
			if(ret == 0)
				printf("process killed\n");
			else
				printf("process does not exist\n");
			break;

		case 'h':
			printf("--------------------------------------------------\n");
			printf(" usage\n");
			printf("command -flag <process_id>");
			printf("flags\n");
			printf("-h \t help\n");
			printf("-k\t kill\n");

	}


}
