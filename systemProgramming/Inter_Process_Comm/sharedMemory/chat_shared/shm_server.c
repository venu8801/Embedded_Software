/* shared memory between two processes */
/* server side code */
#include<stdio_ext.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/shm.h>
#define KEY 0x112233
void main()
{
	int shmid, ret;
	char *ptr;

	//creating shared memory
	shmid = shmget(KEY, 512 , IPC_CREAT | 0664);
       if(shmid < 0)
       {
		printf("failed to create shared memory\n");
		exit(1);

       }
	//attaching shared memory to this process
	ptr = shmat(shmid,NULL,0 );
	printf("shmaddr: %p\n",ptr);
	sleep(5);
	printf("%s\n",ptr);
	ret = shmdt(ptr);  //detaching shared memory to this process	

}
