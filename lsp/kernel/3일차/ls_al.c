#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	 DIR *dp;
	 int i = 0, cmd;
	 struct dirent *p;
	 cmd = getopt(argc, argv, "a");
	 dp = opendir(".");
	 while(p = readdir(dp))
	 {
	 	if (cmd !='a')
	 	{
	 		if(p->d_name[0] == '.')
	 			continue;
	 	}
	 	printf("%-16s", p->d_name);
	 	if((i + 1) % 5 == 0)
	 		printf("\n");
	 	i++;
	 }
	 printf("\n");
	 closedir(dp);
	 return 0;
}