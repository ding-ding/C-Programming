#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define ERROR	-1

int main(void)
{
	int filedes;	// File Descriptor
	char pathname[] = "temp.txt";
	if((filedes = open(pathname, O_CREAT | O_RDWR | O_EXCL, 0644)) == ERROR)
	{		// pathname : 파일명 , O_CREAT : 파일 생성, O_RDWR : 읽고 쓰기, O_EXCL: 파일 존재 유무 , 0644 권한 
		printf("File Open Error\n");
		exit(1);
	}
	printf("fd = %d\n", filedes);
	close(filedes);	//open 의 세트

	return 0;
}
