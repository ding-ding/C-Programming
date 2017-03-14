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
		printf("status : 0x%x\n", WEXITSTATUS(status));
		// 비정상 종료 되었으므로 앞쪽 8bit 가 0으로 채워져있다. 
	}
	else if(pid == 0)
		abort();	// 비정상 종료
	else
	{
		perror("fork() ");
		exit(-1);
	}

	return 0;
}
