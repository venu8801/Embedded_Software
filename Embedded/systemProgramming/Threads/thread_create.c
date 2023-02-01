/* using pthread_create() function to 
 * create threads */

#include<stdio.h>
#include<pthread.h>
void *thread_handler(void *ptr);
void main()
{

	pthread_t ti; // thread id
		      //
	int ret, b = 5;
	
	ret = pthread_create(&ti, 0, thread_handler, b);
	if(ret == 0)
		printf("thread created\n");
	printf("thread id: %lu\n", ti);
	//sleep(15);
	pthread_exit(2);

}
void *thread_handler(void *ptr)
{
	//sleep(1);
	printf("inside thread handler function\n");
	printf("from thread-->\nthread id: %lu\n",pthread_self());
	int i = 0;
	printf("ilim = %lu\n",(long int *)ptr);
	for(i = 0; i < (int *)ptr; i++)

	{
		printf("i : %d\n",i);
		sleep(1);
	//	exit(1);
	}

	
}
