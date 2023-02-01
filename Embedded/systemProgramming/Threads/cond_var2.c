#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condVar = PTHREAD_COND_INITIALIZER;
int glob = 0, i = 0;
void* thread_1(void *arg)
{
	
	int lim = *(int *)arg;
	for(; i < lim; i++)
	{
		pthread_mutex_lock(&mtx);

		if(glob > 50)
		{
			glob++;
			printf("glob t1 : %d\n",glob);
			pthread_cond_signal(&condVar);
		}
		else(glob <= 100)
		{
			pthread_cond_wait(&condVar, &mtx);
		}
		else
			return;
		pthread_mutex_unlock(&mtx);


	}

}
void* thread_2(void *arg)
{
	
	int lim = *(int *)arg;
	for(; i < lim;)
	{
		pthread_mutex_lock(&mtx);
		if(glob <= 50)
		{
			glob++;
			printf("glob t2 : %d\n",glob);
			pthread_cond_signal(&condVar);
		}
		else if(glob <= 100)
		{
			pthread_cond_wait(&condVar, &mtx);
		}
		else
			return;
		pthread_mutex_unlock(&mtx);


	}

}
void main()
{
	
	pthread_t t1, t2;
	int lim = 100;
	pthread_create(&t1, 0 , thread_1, &lim);
	pthread_create(&t2, 0 , thread_2, &lim);
	printf("thread created: %lu\n",t1);
	printf("thread created: %lu\n",t2);
	pthread_join(&t1, NULL);
	pthread_join(&t2,NULL);

}
