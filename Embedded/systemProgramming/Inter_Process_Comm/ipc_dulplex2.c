/* program to construct full duplex pipe to make 2 way communication*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
void main()
{
	pid_t pid;

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



		/* writing to pipe-1*/
		close(fd1[0]); //closing read from pipe-1
		write(fd1[1], "from parent to child", strlen("from parent to child"));


		/* reading from pipe-2*/
		close(fd2[1]); //closing write from pipe-2
		ret1 = read(fd2[0], p2_buf, 100);
		printf("ret1 : %d\n",ret1);
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
		printf("ret2 : %d\n",ret2);
		p1_buf[ret2];
		printf("in child----p1_buf: %s\n", p1_buf);


			/*writing to pipe-2*/
		close(fd2[0]); //closing read in pipe-2
	 	write(fd2[1], "from child to parent", strlen("from child to parent"));
		exit(0);	

	}


}
