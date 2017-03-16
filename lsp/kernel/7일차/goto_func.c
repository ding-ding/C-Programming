#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <fcntl.h>
			// 함수에서 쓰는 goto  
jmp_buf env;		// setjmp의 기준점, 라이브러리에 선언되어있는 구조체

void test(void)
{
	printf("test1\n");
	longjmp(env, 1);		// longjmp : goto의 실행 역활
	printf("test2\n");
}

int main(void)
{
	int ret;
	if((ret = setjmp(env)) == 0)	// 처음엔 무조건 0을 반환, setjmp : goto 의 레이블 
		test();
	else if(ret > 0)
		printf("error\n");

	return 0;
}
