#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;
void *routine()
{
	printf("routine id: %d\n", getpid());
	printf("hello from main thread routine x: %d\n", x);
	x++;
	sleep(2);
	return NULL;
}

void *routine2()
{
	printf("routine2 id: %d\n", getpid());
	sleep(2);
	printf("hello from main thread routine x: %d\n", x);
	return NULL;
}

int main(int ac, char **av)
{
	pthread_t t1;
	pthread_t t2;

	if(pthread_create(&t1, NULL, &routine, NULL))
	{
		return 1;
	}
	if(pthread_create(&t2, NULL, &routine2, NULL))
	{
		return 2;
	}
	if(pthread_join(t1, NULL))
	{
		return 3;
	}
	if(pthread_join(t2, NULL))
	{
		return 3; 
	}

	return 0;
}