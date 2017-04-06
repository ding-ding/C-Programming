#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char **argv)
{
	DIR *dp;
	int i = 0, cmd;
	struct dirent *p;
	int flag = 0;
	while((cmd = getopt(argc, argv, "alRi")) > 0)
	{
		switch(cmd)
		{
			case 'a':
				flag |= 1;
				break;
			case 'l':
				flag |= 2;
				break;
			case 'R':
				flag |= 4;
				break;
			case 'i':
				flag |= 8;
				break;
		}
	}

	dp = opendir(".");
	while(p = readdir(dp))
	{
		if(!(flag & 1))
		{
			if(p->d_name[0] == '.')
				continue;
		}
		printf("%-16s", p->d_name);
		if((i +1) % 5 == 0)
			printf("\n");
		i++;
	}
	printf("\n");
	closedir(dp);
	return 0;
}
