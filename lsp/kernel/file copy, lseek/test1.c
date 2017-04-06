#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int rst, i;
	char *str[] = {"a.txt", "b.txt", "c.txt", "d.txt", "e.txt"};

	for(i = 0; i < 5;i++)
	{
		rst = open(str[i], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		write(rst, argv[i+1], strlen(argv[i+1]));
		if(strlen(argv[i+1]) > 14)
			printf("%s\n", str[i]);
	}
	close(rst);
	return 0;
}