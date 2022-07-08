#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int ac, char **av)
{
	int pid = fork();
	if(pid == -1)
		return 1;
	printf("hello from main proccess\n");
	printf("proccess id: %d \n", getpid());
	printf("pid: %d\n", pid);
	if(pid != 0)
		wait(NULL);
	int x = 2;
	printf("x: %d\n", x);
	if(pid == 0)
		x++;
	printf("x: %d\n", x);
	return 0;		
}