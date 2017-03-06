#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int filedes;
	off_t newpos;

	filedes = open("data1.txt", O_RDONLY);
			
	newpos = lseek(filedes, (off_t)0, SEEK_END);
		//	fd    ,   기준점, 끝
	printf("file size : %d\n", newpos);

	return 0;
}
