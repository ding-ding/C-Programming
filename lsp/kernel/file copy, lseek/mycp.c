#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int src, dst, ret;
	char buf[1024];
	if(argc != 3)
	{
		printf("Arguement Failed\n");
		printf("Usage : exe_file source destunation\n");
		exit(-1);
	}
	src = open(argv[1], O_RDONLY);
	dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while(ret = read(src, buf, sizeof(buf)))
		write(dst, buf, ret);
	close(src);
	close(dst);
	return 0;
}