#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main(void)
{
	int status;
	pid_t pid;
	if((pid = fork()) > 0)
	{
		wait(&status);
		printf("prompt > ");
	}
	else if(pid == 0)
		execlp("ps", "ps", "-e", "-f", 0);

	return 0;
}
