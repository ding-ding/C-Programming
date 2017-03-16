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
			// 비정상종료후 막힌 곳과 경계를 core dump라 한다
		else if(((status >> 8) &0xff) == 0)
			printf("(signal)status : 0x%x\n", status & 0x7f);
	}
	else if(pid == 0)
		abort();	// abort는 6을 반환함, SIGABRT(kill -l 하면 나옴)
	else
	{
		perror("fork() ");
		exit(-1);
	}

	return 0;
}
