/* conditional variables for mutual exclusion issues */
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
int glob = 0;
void* thread_1(void *arg)
{
	int loop,  i, local;
	loop = *(int *)arg;
	for(i = 0; i < loop; i++)
	{
		pthread_mutex_lock(&mtx);
		if(glob < 10)
			pthread_cond_wait(&cond, &mtx);
		else
			pthread_cond_signal(&cond);
		local = glob;
		local++;
		glob = local;
		//pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mtx);
		printf("t1 glob: %d\n",glob);

	}

}
void* thread_2(void *arg)
{
	int loop,  i, local;
	loop = *(int *)arg;
	for(i = 0; i < loop; i++)
	{
		pthread_mutex_lock(&mtx);
		if(glob > 10)
			pthread_cond_wait(&cond,&mtx);
		else
			pthread_cond_signal(&cond);
		local = glob;
		local++;
		glob = local;
		//pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mtx);
		printf("t2 glob: %d\n",glob);
		

	}
}
void main()
{
	pthread_t t1, t2;
	int loop = 10;
	pthread_create(&t1, 0, thread_1, &loop);
	pthread_create(&t2, 0, thread_2, &loop);

	pthread_join(&t1, NULL);
	pthread_join(&t2, NULL);

	printf("glob: %d\n",glob);

}
