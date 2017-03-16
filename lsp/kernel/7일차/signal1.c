#include <stdio.h>
#include <signal.h>

void my_sig(int signo)
{
	printf("my_sig called\n");
}

int main(void)
{
	void (*old_p)(int);
	old_p = signal(SIGINT, my_sig);
	pause();		
	signal(SIGINT, old_p);
	pause();
	for(;;)
		;
	return 0;
}