/* program to construct full duplex pipe to make 2 way communication*/
/* parent process will send a string which needs to be toggled and printed*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
void main()
{
	pid_t pid;
	char pstr[1000];
	char cstr[1000];


	int ret1, ret2;
	int fd1[2], fd2[2];  //array of fd indexes for parent and child
	
	/* creating pipe 1 */
	ret1 = pipe(fd1);
	printf("return value from parent: %d\n",ret1);


	/* creating pipe 2*/
	ret2 = pipe(fd2);
	printf("return value from parent: %d\n",ret2);



	char p1_buf[100]; //pipe 1 buffer
	char p2_buf[100]; //pipe 2 buffer
	pid = fork();

	if(pid < 0)
	{	
		printf("failed to create child process\n");
		exit(1);
	}
	else if(pid > 0)
	{
		/* in parent*/
		printf("[p] enter the string to child:");
		scanf("%[^\n]",pstr);
		int i;
	
		/* writing to pipe-1*/
		close(fd1[0]); //closing read from pipe-1
		write(fd1[1], pstr, strlen(pstr));


		/* reading from pipe-2*/
		close(fd2[1]); //closing write from pipe-2
		ret1 = read(fd2[0], p2_buf, 100);
		p2_buf[EOF] = '\0';
		printf("ret1 : %d\n",ret1);
		for(i = 0; p2_buf[i] != '\0'; i++)
		{
			if( ((p2_buf[i] >= 'A') && (p2_buf[i] <= 'Z')) )
					p2_buf[i] += 32;	
			else if((p2_buf[i] >= 'a') && (p2_buf[i] <= 'z'))
				p2_buf[i] -= 32;
				

		}
		p2_buf[ret1] = '\0';
		printf("in parent---p2_buf: %s\n", p2_buf);  // pipe_2 buffer 
		exit(0);

	}
	else
	{
		/* in chid */

		/* reading from pipe-1*/
		close(fd1[1]); //closing write in pipe-1
		ret2 = read(fd1[0], p1_buf, 100);
		p1_buf[ret2] = '\0';
		printf("ret2 : %d\n",ret2);
		int i;
		for(i = 0; p1_buf[i] != '\0'; i++)
		{
			if( ((p1_buf[i] >= 'A') && (p1_buf[i] <= 'Z')) )
					p1_buf[i] += 32;	
			else if((p1_buf[i] >= 'a') && (p1_buf[i] <= 'z'))
				p1_buf[i] -= 32;
				

		}
		printf("in child----p1_buf: %s\n", p1_buf);


			/*writing to pipe-2*/
		printf("[c] enter string to parent:");
		scanf("%[^\n]",cstr);
		close(fd2[0]); //closing read in pipe-2
	 	write(fd2[1],cstr, strlen(cstr));
		exit(0);	

	}


}
