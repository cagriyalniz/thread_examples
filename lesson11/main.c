#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel = 0;

void *fuel_filling(void *ar)
{
	int i = 0;
	while(i < 5)
	{
		pthread_mutex_lock(&mutexFuel);
		fuel += 15;
		pthread_mutex_unlock(&mutexFuel);
		printf("Filled fuel... %d\n", fuel);
		pthread_cond_signal(&condFuel);
		sleep(1);
		i++;
	}
	return NULL;
}

void *car(void *ar)
{
	pthread_mutex_trylock(&mutexFuel);
	while (fuel < 40)
	{
		printf("No fuel. Waiting...\n");
		pthread_cond_wait(&condFuel, &mutexFuel);
		sleep(1);
	}
	
	fuel -= 40;
	printf("Got fuel. Now left: %d\n", fuel);
	pthread_mutex_unlock(&mutexFuel);
	return NULL;
}

int main()
{
	pthread_t th[2];
	int i = 0;
	pthread_mutex_init(&mutexFuel, NULL);
	pthread_cond_init(&condFuel, NULL);
	while (i < 5)
	{
		if (i == 4)
		{

			if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
			{
				perror("Failed to create thread");
			}
		}
		else
		{
			if (pthread_create(&th[i], NULL, &car, NULL) != 0)
			{
				perror("Failed to create thread");
			}
		}
		i++;
	}
	i = 0;
	while(i < 5)
	{
		if(pthread_join(th[i], NULL) != 0)
		{
			perror("Failed to join thread");
		}
		i++;
	}
	pthread_mutex_destroy(&mutexFuel);
	pthread_cond_destroy(&condFuel);
}