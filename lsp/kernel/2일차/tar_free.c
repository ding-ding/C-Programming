#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct 
{
	char fname[20];
	int fsize;
}F_info;

#define min(x, y) 	(((x) < (y)) ? (x) : (y))

int readn(int fd, void *buff, int len)	// init struct 
{
	char *tmp = (char *)buff;	// struct
	int checksum = len;			// struct size = 24
	int ret;					// file size
	while(checksum > 0)
	{
		if((ret = read(fd, tmp, checksum)) == 0)	// ret = file exist ? 24 : 0
			return 0;
		checksum -= ret;		
		tmp += ret;			// pointer tmp가 다음 주소를 받을 수 있도록 가리키는 위치를 뒤로 밀어줌
	}
	return len;
}

int main(int argc, char **argv)
{
	int src, dst, len, ret;
	F_info info;
	char buf[1024] = "";
	src = open(argv[1], O_RDONLY);
	while(readn(src, &info, sizeof(info)))
	{
		dst = open(info.fname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		while(info.fsize > 0)
		{
			len = min(sizeof(buf), info.fsize);
			ret = read(src, buf, len);
			write(dst, buf, ret);
			info.fsize -= ret;
		}
		close(dst);
	}
	close(src);
	return 0;
}
