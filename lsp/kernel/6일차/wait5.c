#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int status;
	if((pid = fork()) > 0)
	{
		wait(&status);
		if((status & 0xff) == 0)
			printf("(exit)status : 0x%x\n", WEXITSTATUS(status));
		else if(((status >> 8) &0xff) == 0)
			printf("(signal)status : 0x%x, %s\n", status & 0x7f, 
				((status >> 7) & 1) ? "core dumped" : "");
	}
	else if(pid == 0)
		abort();	
	else
	{
		perror("fork() ");
		exit(-1);
	}

	return 0;
}
