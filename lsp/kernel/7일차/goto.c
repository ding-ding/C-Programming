#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdlib.h>


int main(void)
{
	int ret;
	char buf[1024];
	if((ret = read(0, buf, sizeof(buf))) > 0)
		goto err;

	return 0;
	err:
		perror("read() ");
		exit(-1);
}