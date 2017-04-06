#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	fd = open("a.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	close(1);
	dup(fd);		// 가장 최근에 close 해준 공간을 fd가 대신하게 해준다. 
	printf("can i???????????\n");	//표준 입력(stdin), fd가 대신하므로 fd에 printf 가 출력된다. 
	return 0;
}
