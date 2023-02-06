// program to demonstrate dead lock 
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void main()
{
	pthread_t t1;
	t1 = pthread_self();
	printf("pthread: %lu\n",t1);
	pthread_mutex_lock(&mtx);	

	pthread_mutex_lock(&mtx);	
	pthread_mutex_unlock(&mtx);	
	exit(1);
	
}
