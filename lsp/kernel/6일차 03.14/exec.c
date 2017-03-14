#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main(void)
{
	execlp("ps", "ps", "-e", "-f", 0); 	// (대상, 벡터0, 벡터1, 벡터2, 0) 0번째를 실행
						//exec는 이거만 실행하고 끝
	return 0;
}
