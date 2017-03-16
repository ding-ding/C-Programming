#include <stdio.h>
#include <signal.h>

int main(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);	
	signal(SIGKILL, SIG_IGN);	// kill을 SIG_IGN 를 할수 없다
	pause();			// 끄려면 kill -9 pid
	return 0;			
}
