#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *routine(void *ar)
{

	if (pthread_mutex_lock(&mutex) == 0)
	{
		printf("%d \n", *(int *)ar);
		printf("Got lock \n");
		sleep(1);
		if (pthread_mutex_unlock(&mutex) == 0)
		{
			printf("%d \n", *(int *)ar);
			printf("unlock\n");
		}
		else
		{
			printf("%d \n", *(int *)ar);
			printf("didnt unlock \n");
		}
	}
	else
	{
		printf("%d \n", *(int *)ar);
		printf("didnt get lock \n");
	}
	free(ar);
	return NULL;
}

int main()
{
	pthread_t th[4];
	pthread_mutex_init(&mutex, NULL);
	int i = 0;
	while (i < 4)
	{
		int *a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
		{
			perror("Error at creating thread");
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(th[i], NULL))
		{
			perror("Error at joining thread");
		}
		i++;
	}
}