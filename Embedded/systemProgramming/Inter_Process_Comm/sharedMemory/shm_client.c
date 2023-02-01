/* client side code */
/* client only accesses shared memory created by server	*/
#include<stdio_ext.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
#include<stdlib.h>
#define KEY 0x112233
void main()
{


	int shmid, ret;
	char *ptr;
	shmid = shmget(KEY, 512, 0);
	ptr = shmat(shmid, NULL, 0);
	printf("shmaddr: %p\n",ptr);
	strcpy(ptr,"hello venu gopal");
	shmdt(ptr);
}
