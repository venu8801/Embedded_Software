/* printing even and odd numbers using threads*/
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int num = 0;
void *subthread_1(void *ptr)
{
	
	printf("subthread id: %lu\n",pthread_self());
	int i;
	for(i = 0; i < 100; i++)
	{
		pthread_mutex_lock(&mtx);
		if(num % 2 != 0)
		{

			printf("j : %d\n",num);
			num++;
		}
		else
		{
			pthread_cond_wait(&cond, &mtx);
		}
		pthread_mutex_unlock(&mtx);
			pthread_cond_signal(&cond);
		//sleep(1);
	}
//	exit(1);
}



void *subthread_2(void *ptr)
{
	printf("subthread id: %lu\n",pthread_self());
	int i;
	for(i = 0; i < 100; i++)
	{
		pthread_mutex_lock(&mtx);
		if(num % 2 == 0)
		{

			printf("\ti : %d\n",num);
			num++;
		}
		else
		{
			pthread_cond_wait(&cond, &mtx);
		}
		pthread_mutex_unlock(&mtx);
			pthread_cond_signal(&cond);
	}
//exit(1);
}



void main()
{
	pthread_t s1, s2;

	int tid = pthread_create(&s1, 0, subthread_1, NULL);
	if(tid == 0)
		printf("thread is created\n");
	printf("thread id s1: %lu\n", pthread_self());
	tid = pthread_create(&s2, 0, subthread_2, NULL);
	if(tid == 0)
		printf("thread is created\n");
	printf("thread id s2: %lu\n", pthread_self());
	pthread_join(s1,NULL);
	pthread_join(s2,NULL);
	printf("global \n\n");



}


