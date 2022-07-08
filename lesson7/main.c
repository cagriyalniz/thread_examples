#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10]= {2, 3 ,5 ,7, 11, 13, 17, 19, 23, 29};

void* routine(void *ar)
{

	int index = *(int *)ar;
	printf("%d ", primes[index]);

	return NULL;
}

int main()
{
	pthread_t th[10];
	int i = 0;
	while(i < 10)
	{
		if(pthread_create(&th[i], NULL, &routine, &i) != 0)
		{
			perror("failed to create thread");
		}
				if(pthread_join(th[i], NULL) != 0)
		{
	perror("failed to join thread");
		}
		i++;
	}
/* 	i = 0;
	while(i < 10)
	{
		if(pthread_join(th[i], NULL) != 0)
		{
			perror("failed to join thread");
		}
		i++;
	} */
}