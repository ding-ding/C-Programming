#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	int fd;
	char buff[1024] = "????";
	fd = open("a.txt", O_RDWR);
	close(0);
	dup(fd);
	gets(buff);
	puts(buff);
	printf("print ??\n");
	return 0;
}