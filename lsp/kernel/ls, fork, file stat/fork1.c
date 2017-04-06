#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	pid = fork();
	if(pid > 0)
		printf("parent\n");
	else if(pid == 0)
		printf("child\n");
	else
	{
		perror("fork() ");
		exit(-1);
	}
	return 0;
}