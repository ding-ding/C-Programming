#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	struct stat buf;
	char perm[11] = "----------";
	char rwx[4] = "rwx";		// read write execute
	int i;
	stat(argv[1], &buf);		// argv로 들어온 파일의 정보를 가져옴

	if(S_ISDIR(buf.st_mode))
		perm[0] = 'd';		// directory
	if(S_ISREG(buf.st_mode))
		perm[0] = '-';		// 일반파일 
	if(S_ISFIFO(buf.st_mode))
		perm[0] = 'p';		// pipe
	if(S_ISLNK(buf.st_mode))
		perm[0] = 'l';		// link
	if(S_ISSOCK(buf.st_mode))
		perm[0] = 's';		// socket
	if(S_ISCHR(buf.st_mode))
		perm[0] = 'c';		// char
	if(S_ISBLK(buf.st_mode))
		perm[0] = 'b';		// block
	for(i = 0; i < 9; i++)
		if((buf.st_mode >> (8 - i)) & 1)
			perm[i + 1] = rwx[i % 3];
	printf("%s\n", perm);
	return 0;
}

/* struct stat
short 형태이며 앞쪽 4bit 는 파일의 형태?종류? 를 나타냄
*/
