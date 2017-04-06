#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char ** argv)
{
	struct stat buf;
	char ch;
	stat(argv[1], &buf);
	if(S_ISDIR(buf.st_mode))
		ch = 'd';		// directory
	if(S_ISREG(buf.st_mode))
		ch = '-';		// 일반파일 
	if(S_ISFIFO(buf.st_mode))
		ch = 'p';		// pipe
	if(S_ISLNK(buf.st_mode))
		ch = 'l';		// link
	if(S_ISSOCK(buf.st_mode))
		ch = 's';		// socket
	if(S_ISCHR(buf.st_mode))
		ch = 'c';		// char
	if(S_ISBLK(buf.st_mode))
		ch = 'b';		// block
	printf("%c\n", ch);
	return 0;

}
