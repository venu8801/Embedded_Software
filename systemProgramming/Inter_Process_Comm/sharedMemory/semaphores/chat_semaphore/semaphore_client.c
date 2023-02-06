/* using semaphores in shared memory client and server communication */
/* client side code */
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<sys/sem.h>
#include<sys/shm.h>
#define KEY 0X1998860
void main()
{
	int shmid, semid, ret;
	char *ptr;
	struct sembuf buf;
	while(1)
	{
		shmid = shmget(KEY, 512, 0);
		if(shmid < 0)
		{
			printf("failed to create shared memory\n");
			exit(1);
		}
		semid = semget(KEY, 2, 0);

		ptr = shmat(shmid, NULL, 0);
		if(ptr == NULL)
		{
			printf("failed to attach shared memory to current process\n");
			exit(1);
		}
		//strcpy(ptr, "moschip tech.");	

		printf("[c]: ");
		scanf("%[^\n]",ptr);
		__fpurge(stdin);
		if(strcmp("/exit", ptr) == 0)
			break;

		//setting semaphore one to positve value
		//unblocking server
		buf.sem_num = 0;
		buf.sem_op  = 1;
		buf.sem_flg = 0;

		ret = semop(semid, &buf, 1);

		//blocking client
		buf.sem_num = 1;
		buf.sem_op = -1;
		buf.sem_flg = 0;
		ret = semop(semid, &buf, 1);
		printf("[s]: %s\n",ptr);
	}
	shmdt(ptr);

}
