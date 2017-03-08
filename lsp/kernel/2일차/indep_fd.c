#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(void)
{
	char buf[1024] = "";
	int fd[2] = {0};

	fd[0] = open("tar_free.c", O_RDONLY);
	read(fd[0], buf, 10);
	write(1, buf, 10);

	fd[1] = open("tar_free.c", O_RDONLY);
	read(fd[1], buf, 10);
	write(1, buf, 10);
	return 0;
}
