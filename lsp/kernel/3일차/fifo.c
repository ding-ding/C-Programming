#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*
fifo
mkfifo myfifo =-> mkfifo[파이프 만들기] "myfifo" 
*/

int main(void)
{
	int fd, ret;
	char buf[1024];
	mkfifo("myfifo");
	fd = open("myfifo", O_RDWR);
	for(;;)
	{
		ret = read(0, buf, sizeof(buf));
		buf[ret - 1] = 0;
		printf("Keyboard Input : [%s]\n", buf);
		read(fd, buf, sizeof(buf));
		buf[ret - 1] = 0;
		printf("Pipe Input : [%s]\n", buf);
	}
	return 0;
}
