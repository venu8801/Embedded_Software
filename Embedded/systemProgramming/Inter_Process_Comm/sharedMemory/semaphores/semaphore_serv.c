/* using semaphores in shared memory client and server communication */
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
	shmid = shmget(KEY, 512, IPC_CREAT | 0660);
	if(shmid < 0)
	{
		printf("failed to create shared memory\n");
		exit(1);
	}
	semid = semget(KEY, 2, IPC_CREAT | 0660);
	
	ret = semctl(semid,  0, SETVAL, 0);
	if(ret < 0)
	{
		printf("failed to initialize semaphore set-1\n");
		exit(1);
	}
	ret = semctl(semid, 1, SETVAL, 0);
	if(ret < 0)
	{
		printf("failed to initialize semaphore set-2\n");
		exit(1);
	}


	//for semaphore set 1
	buf.sem_num = 0;
	buf.sem_op  = -1;
	buf.sem_flg = 0;

	ret = semop(semid, &buf, 1);
	ptr = shmat(shmid, NULL, 0);
	printf("%s",ptr);
	
	strcpy(ptr+256, "hello all");

	//for semaphore set 2
	buf.sem_num = 1;
	buf.sem_op = +1;
	buf.sem_flg = 0;
	ret = semop(semid, &buf, 1);
	shmdt(ptr);

}
