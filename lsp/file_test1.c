#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 	1024

int main(void)
{
	int fdin, fdout;
	ssize_t nread;
	char buf[BUFSIZE];
	char pre[BUFSIZE] = "BBBB";
	char aft[BUFSIZE] = "DSP";

	fdin = open("temp1.txt", O_RDONLY);
	fdout = open("temp2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	while((nread = read(fdin, buf, 1024)) > 0)
	{
		if(write(fdout, tmp, arr_size(tmp)) < nread)
		{
			close(fdin);
			close(fdout);
		}
	}

}