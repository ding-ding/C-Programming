#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int daemon_init(void)
{
	int i;
	if(fork() > 0)
		exit(0);
	setsid();
	chdir("/");
	umask(0);
	for(i = 0; i < 64; i++)
		close(i);
	signal(SIGCHLD, SIG_IGN);
	return 0;
}

int main(void)
{
	daemon_init();
	for(;;)
		sleep(20);
	return 0;
}