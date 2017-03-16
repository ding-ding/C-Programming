#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{
	pid_t pid;
	if((pid = fork())> 0)
		sleep(100);
	else if(pid == 0)
		;
	else
	{
		perror("fork()");
		exit(-1);
	}
	return 0;
}
