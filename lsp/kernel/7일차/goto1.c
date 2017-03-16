#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void test(void)
{
	goto err;
}

int main(void)
{
	int ret, flag = 0;
	char buf[1024];
	for(;;)
	{
		for(;;)
		{
			if((ret = read(0, buf, sizeof(buf))) < 0)
			{
				test();
			}
		}
		if(flag)
			break;
	}

	return 0;

	err:
		perror("read() ");
		exit(-1);
}