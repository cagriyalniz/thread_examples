#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int mails = 0;
pthread_mutex_t mutex;

void* routine()
{
	int i = 0;
	while(i < 10000)
	{
	//	pthread_mutex_lock(&mutex);
		mails++;
	//	pthread_mutex_unlock(&mutex);
		i++;
	}
	return (NULL);
}

int main()
{
	pthread_t th[4], tht[9];
	int i = 0;
	//pthread_mutex_init(&mutex, NULL);
/* 	while(i < 4)
	{
		if(pthread_create(th + i, NULL, &routine, NULL) != 0)
		{
			perror("fail");
			return 1;
		}
		printf("Thread %d has started \n", i);
		if(pthread_join(th[i], NULL) != 0)
		{
			return 2;
		}
		printf("Thread %d has finished\n", i);
		i++;
	} */

	i = 0;
	while(i < 9)
	{
		if(pthread_create(tht + i,NULL, &routine, NULL) != 0)
		{
			perror("fail2");
			return 3;
		}
		printf("Thread tht %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < 9)
	{
		if(pthread_join(tht[i], NULL) != 0)
		{
			return 4;
		}
		printf("Thread tht %d has finished\n", i);
		i++;
	}
	
//	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
}