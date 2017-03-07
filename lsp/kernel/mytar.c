#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct 
{
	char fname[20];
	int fsize;
}F_info;

int file_size(int fd)
{
	int fsize, old;
	old = lseek(fd, 0, SEEK_CUR);	// 파일의 현재 위치 
	fsize = lseek(fd, 0, SEEK_END);	// 파일의 크기
	lseek(fd, old, SEEK_SET);	// 파일포인터를 초기위치
	return fsize;
}

int main(int argc, char *argv[])
{
	int src, dst, ret;
	char buf[1024];
	F_info info;
	int i;
	dst = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	for(i = 0; i < argc -2; i++)
	{
		src = open(argv[i+1], O_RDONLY);
		strcpy(info.fname, argv[i+1]);
		info.fsize = file_size(src);
		write(dst, &info, sizeof(info));
		while(ret = read(src, buf, sizeof(buf)))
			write(dst, buf, ret);
		close(src);
	}
	close(dst);

	return 0;
}
