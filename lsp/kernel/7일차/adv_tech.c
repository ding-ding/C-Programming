#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int score;
	char name[20];
}ST;

typedef struct 
{
	int count;
	char name[20];
	int score[0];		// 해당구조체의 끝을 가리키는 포인터 
}FLEX;				// malloc 하는것 보다 score[0]으로 남은공간을 자유롭게 사용하는게 더 효율
				// 시험문제 score[0]으로 트리 짜기
int main(void)
{
	FLEX *p = (FLEX *)malloc(4096);	
	int i;
	for(i = 0; i < 100; i++){
		p->score[i] = i+1;
		printf("p->score[%d] = %d\n", i, p->score[i]);
	}
	p->score[0];
	p->score[1];
	return 0;
}








