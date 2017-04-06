#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char **argv)
{
	struct stat buf;
	struct dirent *p;
	struct passwd *pw; 	// 현재 위치
	struct group *gr;
	struct tm *tm;		// 시간
	char ch;
	char perm[11] = "----------";
	char rwx[4] = "rwx";
	char sst[4] = "sst";
	int i;
	stat(argv[1], &buf);

	if(S_ISDIR(buf.st_mode))
		perm[0] = 'd';
	if(S_ISREG(buf.st_mode))
		perm[0] = '-';
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
	for(i = 0; i < 3; i++)
		if((buf.st_mode >> (11 - i)) & 1)
			if(perm[(i + 1) * 3] == '-')	// 공유 권한이 없으면 대문자, 있으면 소문자
				perm[(i + 1) * 3] = sst[i] ^ 0x20; // 대소문자 변환
			else
				perm[(i + 1) * 3] = sst[i];

	printf("%s", perm);
	printf("\t%d", buf.st_nlink);
	pw = getpwuid(buf.st_uid);
	printf("\t%s", pw->pw_name);
	gr = getgrgid(buf.st_gid);	// st_gid : 강제적으로 루트의 권한을 
	printf("\t%s", gr->gr_name);
	printf("\t%d", buf.st_size);
	tm = localtime(&buf.st_mtime);
	printf("\t%d - %02d - %02d %02d:%02d", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min);
	printf("\n");
	return 0;
}	
