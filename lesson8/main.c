#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void *ar)
{
	int index = *(int *)ar;
	int sum = 0;
	int i = 0;
	while(i < 5)
	{
		sum += primes[index + i];
		i++;
	}
	printf("Locel sum: %d\n", sum);
	*(int*)ar = sum;
	return ar;
}

int main()
{
	pthread_t th[10];
	pthread_t tht[2];
	int i = 0;
	while(i < 2)
	{
		int *a= malloc(sizeof(int));
		*a = i * 5;
		if(pthread_create(&tht[i], NULL, &routine, a) != 0)
		{
			perror("Failed to create thread");
		}
		i++;
	}
	int globalSum = 0;
	i = 0;
	int *r;
	while(i < 2)
	{
		if(pthread_join(tht[i], (void**)&r) != 0)
		{
			perror("Failed to join thread");
		}
		i++;
		printf("r: %d\n", *r);
		globalSum += *r;
		free(r);
	}
	printf("%d",globalSum);
}