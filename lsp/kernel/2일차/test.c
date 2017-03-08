#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd, ret, num = -1;
	char buf[1024] = "";
	fd = open("dup1.c", O_RDONLY);
	while(lseek(fd, num, SEEK_END) != EOF)
	{
		read(fd, buf, 1);
		write(1, buf, 1);
		num--;
	}
	printf("\n");
	close(fd);
	return 0;
}