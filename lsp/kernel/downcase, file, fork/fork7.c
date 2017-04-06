#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int fd, ret;
	char buf[1024];
	pid_t pid;
	fd = open("fork7.c", O_RDONLY);
	pid = fork();
	// 자식은 부모의 변수 및 정보들을 복사한다. 

	if(pid > 0)
		;
	else if(pid == 0)
	{
		ret = read(fd, buf, 10);
		buf[ret] = 0;
		printf("[%s]\n", buf);

	}
	else
	{
		perror("fork() ");
		exit(-1);
	}
	printf("\n");
	return 0;
}
