/* mutual exclusion case */
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_mutex_t var = PTHREAD_MUTEX_INITIALIZER;// creating a mutex object
int glob = 0;
void *thread_fun1(void *arg)
{
	printf("mutex var: %lx\n",var);
	int loop, i , local;
	loop = *(int *)arg;
	for(i = 0; i < loop; i++)
	{
		pthread_mutex_lock(&var);// locking mutex object
		local = glob;
		local++;
		glob = local;
		pthread_mutex_unlock(&var);// unlocking mutex object
	}


}
void *thread_fun2(void *arg)
{
	
	int loop, i , local;
	loop = *(int *)arg;
	for(i = 0; i < loop; i++)
	{
		pthread_mutex_lock(&var);// locking mutex object
		local = glob;
		local++;
		glob = local;
		pthread_mutex_unlock(&var);// unlocking mutex object
	}

}
void main()
{
	void *ret;

	pthread_t t1, t2;

	int res, loop = 600;

	pthread_create(&t1, 0, thread_fun1, &loop);
	pthread_create(&t2, 0, thread_fun2, &loop);

	pthread_join(t1, &ret);
	pthread_join(t2,&ret);

	printf("gob : %d\n",glob);

}



