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
	setsid();			// 세션 아이디 갱신 받기
	chdir("/");			// 루트로 이동
	umask(0);			// 파일의 실행권한을 막는다. 권한 666, 디렉토리는 777
	for(i = 0; i < 64; i++)		// 기본적으로 프로세스만들때 64개 
		close(i);		// 그것을 모두 close 해준다. 
	signal(SIGCHLD, SIG_IGN);	// SIGCHLD를 무시
	return 0;
}

int main(void)
{
	daemon_init();
	for(;;)
		sleep(20);
	return 0;
}
