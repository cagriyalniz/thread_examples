#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;

pthread_mutex_t mutex;
void* routien()
{
	int i = 0;
	while(i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return NULL;
}

int main()
{
	pthread_t p1, p2, p3, p4;
	pthread_mutex_init(&mutex, NULL);
	if(pthread_create(&p1, NULL, &routien, NULL) != 0)
	{
		return 1;
	}
	if(pthread_create(&p2, NULL, &routien, NULL) != 0)
	{
		return 2;
	}
	if(pthread_create(&p3, NULL, &routien, NULL) != 0)
	{
		return 3;
	}
	if(pthread_create(&p4, NULL, &routien, NULL) != 0)
	{
		return 4;
	}
	if(pthread_join(p1, NULL) != 0)
	{
		return 5;
	}
	if(pthread_join(p2, NULL) != 0)
	{
		return 6;
	}
	if(pthread_join(p3, NULL) != 0)
	{
		return 7;
	}
	if(pthread_join(p4, NULL) != 0)
	{
		return 8;
	}
	pthread_mutex_destroy(&mutex);
	printf("number of mails: %d\n", mails);
}