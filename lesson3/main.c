#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

int mails = 0;

void*routine()
{
	int i = 0;
	while(i < 100)
	{
		mails++;
		i++;
	}
	sleep(2);
	

	return NULL;
}

int main()
{
	pthread_t p1, p2;
	//pid_t pp1;
	//pp1 = fork();// <0 error =0 child >0 parrent

		if(pthread_create(&p1, NULL, &routine, NULL)!= 0)
		{

			return 1;
		}

		if(pthread_join(p1, NULL)!= 0)
		{
			return 2;
		}

		if(pthread_create(&p2, NULL, &routine, NULL) != 0)
		{
			return 3;
		}
		if(pthread_join(p2, NULL) != 0)
		{
			return 4;
		}


	printf("\nNumber of mails: %d\n", mails);

}