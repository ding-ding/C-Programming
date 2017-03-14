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
		wait(&status);	// 자식이 죽을때 까지 기다린다
		printf("status : 0x%x\n", (status >> 8) & 0xff);
		// 자식은 정상종료 되었고 뒤쪽 8bit 가 0으로 채워져 있으므로 쉬프트 연상 8을 해주어야 
		// 정상적인 전달값이 나온다. 
	}
	else if(pid == 0)
		exit(7);	// 자식이 죽고 부모에게 7을 전달한다.
		
	else
	{
		perror("fork() ");
		exit(-1);
	}

	return 0;
}
