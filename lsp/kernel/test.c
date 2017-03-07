#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
/*
test.txt 라는 파일에 "Test Programming" 이라는 내용을 집어넣었다.
슬기가 의도한 것은 "Test Project with Fire Truck" 이였다.
lseek 를 활용하여 이를 구현해보시오.
*/

int main(int argc, char *argv[]) {
	int fd;
	char buf[100] = "Project with Fire Truck\n"; 
	fd = open(argv[1], O_RDWR, 0644);

	if(fd == -1)
		printf("ERROR\n");

	lseek(fd, (off_t)5, SEEK_SET);
	write(fd, buf, strlen(buf));

	close(fd);
	return 0;
}