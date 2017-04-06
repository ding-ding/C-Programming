#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>

void recursive_dir(char *dname);
void printStat(char *, char *, struct stat*);
char type(mode_t);
char *perm(mode_t);


int main(int argc, char *argv[])   
{
	recursive_dir(".");
	return 0;
}

void recursive_dir(char *dname)
{
	struct dirent *p;
	struct stat buf;
	DIR *dp;
	chdir(dname);
	dp = opendir(".");
	printf("\t%s : \n", dname);
	while(p = readdir(dp))
		printf("%s\n", p->d_name);
	rewinddir(dp);
	while(p = readdir(dp))
	{
		stat(p->d_name, &buf);
		if(S_ISDIR(buf.st_mode)){
			if(strcmp(p->d_name, ".") && strcmp(p->d_name, "..")){
			// strcmp 시 같으면 0을 str1이 클경우 양수, str2가 클경우 음수, 출력값은 규칙없음
				// printf("%c\n", strcmp(p->d_name, "."));
				// printStat(".", p->d_name, &buf);
				// putchar('\n');
				recursive_dir(p->d_name);
			}
		}
	}
	// chdir("..");
	closedir(dp);
}

// void printStat(char *pathname, char *file, struct stat *st)
// {
// 	printf("%5d ", st->st_blocks);
// 	// printf("%c%s ", type(st->st_mode), perm(st->st_mode));
// 	printf("%3d ", st->st_nlink);
// 	printf("%s %s ", getpwuid(st->st_uid)->pw_name, getgrgid(st->st_gid)->gr_name);
// 	printf("%9d ", st->st_size);
// 	printf("%.12s ", ctime(&st->st_mtime)+4);
// 	printf("%s", file);
// }
