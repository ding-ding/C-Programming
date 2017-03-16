#include <stdio.h>
#include <signal.h>

void my_sig(int signo)
{
	printf("my_sig called\n");
}

void my_sig2(int signo)
{
	printf("my_sig2 called\n");
}

int main(void)
{
	void(*old_p)(int);
	old_p = signal(SIGINT, my_sig);		// 이전에 등록한 시그널의 핸들러
	pause();
	printf("%d\n", old_p);			// 이전에 등록한 시그널이 없으므로 0을 반환
	old_p = signal(SIGINT, my_sig2);	// my_sig를 반환한다. 
	pause();
	printf("%d\n", old_p);
	signal(SIGINT, old_p);
	for(;;)
		;

	return 0;
}
