#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int i;
	int status;
	pid_t pid;

	if((pid = fork()) > 0)
	{
		wait(&status);
		printf("prompt > ");
	}
	else if(pid == 0)
		execl("./newpgm", "newpgm", "one",  "two", (char *)0);
	return 0;

}