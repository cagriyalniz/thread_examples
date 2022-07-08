#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
void* roll_dice()
{
	int value = (rand() % 6) + 1;
	printf("%d\n", value);
	int *res = malloc(sizeof(int));
	*res = value;
//	printf("Thread result: %p\n", res);
	return (void*)res;
}

int main(int argc, char const *argv[])
{
	int* res;
	srand(time(NULL));
	pthread_t th;
	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
	{
		return 1;
	}
	if(pthread_join(th,(void**) &res) != 0)
	{
		return 2;
	}
	printf("Result: %d\n", *res);
	int i = 0;
	int *res2;
	pthread_t tht[9];
	while(i < 9)
	{
		if(pthread_create(tht + i, NULL, &roll_dice, NULL) != 0)
		{
			return 1;
		}
		if(pthread_join(tht[i], (void**)&res2) != 0)
		{
			return 2;
		}
		printf("dice: %d\n", *res2);
		i++;
	}

	printf("Main result: %p\n", res);
	free(res);

	return 0;
}
