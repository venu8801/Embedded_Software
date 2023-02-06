#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>

void printAddr(char **dptr);
void seperate_Commands(char *str, char**dptr);

void main()
{
	char str[1000];
	char *ptr[30];  // 30 pointers of type char *
	int stat = 0;
	pid_t pid, cpid;
	printf("-------------bash clone----------------\n");

	while(1)
	{
		printf("venus_bash #: ");
		gets(str);
		printf("entered string: %s\n",str);
		printf("----------------------------\n"); 

		if(strcmp("exit", str) == 0)
			exit(0);
		
		seperate_Commands(str, ptr);
		printAddr(ptr);
		pid = fork();
		if(pid < 0)
		{
			printf("failed to create child process\n");
			exit(2);
		}
		else if(pid > 0)
		{
			/*executes in parent process*/
			cpid = wait(&stat);
			printf("child process terminated cpid: %d\n",cpid);


		}
		else
		{
			/* in child*/
			
			execvp(ptr[0], ptr);
			

		}


	}
	

}
void seperate_Commands(char *str, char**dptr)
{
	

	int i, j;
	dptr[0] = str; //array of pointers
	for(i = 0, j = 1; str[i] != '\0'; i++)
	{
		if(str[i] == ' ')
		{
			str[i] = '\0';
			if(str[i+1] != '\0')
			{
				dptr[j] = &str[i+1];
				j++;
			}

		}
	}
	dptr[j] = NULL;

}
void printAddr(char **dptr)
{
	printf("------Addresses inside array of char pointers----------------\n");
	
	int i = 0;
	while(dptr[i] != NULL)
	{

		printf(" ptr[%d]: %s  --- address of string:%p\n", i, dptr[i], dptr[i]);
		i++;
	}
	printf("------------------------------------------------------------\n");



}
