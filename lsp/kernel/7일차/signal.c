#include <signal.h>
#include <stdio.h>

void my_sig(int signo)
{
	printf("my_sig called\n");
}

int main(void)
{
	signal(SIGINT, my_sig);		//SIGINT : SIGNAL intterupt (ctrl+c)
	for(;;)				// 기본적으로 모든 프로세스는 신호(signal)을 받으면 죽는다 
		;			// 예외(SIGCHD)
	return 0;
}
