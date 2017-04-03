#if 0
1. 아래 Code를 작성하고 이 Code의 기계어에 대한 그림을 그리고 분석하시오.

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int num1 = 3, num2 = 7;
    swap(&num1, &num2);
    return 0;
}

배점 : 20점
2. RB Tree에 3, 7, 10, 12, 14, 15, 16, 17, 19, 20을 넣을 때의 그림을 그리시오.

배점 : 2점
3. 단 한 번의 연산으로 대소문자 전환을 할 수 있는 연산에 대해 기술하시오.

#include <stdio.h>

int main(void)
{
	char num = 'A';

	num ^= 0x20;

	printf("num = %c\n", num);
}
#endif
#if 0
배점 : 2점
4. Stack과 Queue의 차이점에 대해 작성하시오.

stack 은 먼저 들어온 데이터가 가장 나중에 나간다 lifo
queue 은 먼저 들어온 데이터가 가장 먼저 나간다 fifo

#endif
#if 0
배점 : 3점
5. 임의의 값 x가 있는데, 이를 8192 단위로 정렬하고 싶다면 어떻게 해야할까 ?
   (힌트 : 8192 = 2^13)

배점 : 2점
6. int *p[4]와 int (*p)[4]의 차이에 대해 기술하시오.

배점 : 2점
7. int[4][4]배열이 메모리 공간에 나란히 존재함을 증명하라!

#include <stdio.h>

int main(void)
{
	int arr [4][4] = {{1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}};
	int (*p)[4] = arr;

	printf("1arr %d\n", **p);
	printf("1arr %d\n", **p + 1);
	
	return 0;
}
#endif
#if 0
배점 : 2점
8. int num = 7, 육중 포인터(******)를 이용해서 이를 표현하라!

배점 : 3점
9. char *str = "Pointer Is Very Important"라는 문자열이 있다
   여기에 대문자가 총 몇 개 사용되었는지 세어보자(프로그래밍으로)

#include <stdio.h>

int main(void)
{
	int i, cnt = 0;
	char *str = "Pointer Is Very Important";

	for(;*str;)
	{
		if(*str >= 65 && *str <= 90)
			cnt++;
		str++;
	}	
	printf("%d\n", cnt);
	return 0;
}
#endif
#if 0
배점 : 3점
10. int arr1[3][3] = {{1, 3, 6}, {7, 1, 9}, {3, 7, 5}}과
    int arr2[3][3] = {{3, 5, 7}, {9, 1, 8}, {5, 1, 2}}중
    배열의 각 요소의 합이 가장 큰 것은 무엇인가 ?(프로그래밍)

#include <stdio.h>
int arr_sum(int arr[3][3])
{
	int i, j;
	int sum = 0;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			sum += arr[i][j];

	return sum;
}

int main(void)
{
	int arr1[3][3] = {{1, 3, 6}, {7, 1, 9}, {3, 7, 5}};
	int arr2[3][3] = {{3, 5, 7}, {9, 1, 8}, {5, 1, 2}};
	int sum1 = 0, sum2 = 0;
	sum1 = arr_sum(arr1);
	sum2 = arr_sum(arr2);

	printf("sum1 = %d, sum2 = %d\n", sum1, sum2);

	return 0;
}
#endif
#if 0
배점 : 1점
11. int형 변수 3개를 할당하고자 하여 아래와 같은 코드를 작성하였다.
    int *dyn_arr = (char *)malloc(sizeof(char) * 3);에서 잘못된 부분을 정정하라
#endif

#if 0
배점 : 2점
12. 아무 문자열을 calloc을 통해 동적할당하고 그 문자열을 배열로 옮겨보라

#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int i;
	char *str = (char *)calloc(20, sizeof(char));
	str = "Pointer Is Very Important";
	char arr[30];

	for(i = 0;*str;i++)
	{
		arr[i] = *str;
		str++;
		printf("%c", arr[i]);
	}
	printf("\n");

	return 0;
}

배점 : 3점
13. 임의의 구조체를 한 개 만들고 해당 구조체에 대한 변수 2개를 선언한 이후
    구조체의 멤버들에 적절한 값을 입력한 후 해당 값을 서로 교환해보라
#endif

#if 0
배점 : 3점
14. 7명의 직원에 대한 급여를 입력받는다.
    이들이 받는 급여의 평균을 출력하고 평균 이상을 받는 사람들의 이름을 출력하라

배점 : 2점
15. Intel Architecture와 ARM Architecture의 차이점은 ?

배점 : 2점
16. 이것이 없으면 C 언어를 사용할 수 없다.
    이것은 무엇일까 ?
header file 

배점 : 2점
17. 3을 좌측으로 3 Shift 하는 코드를 작성하고
    8을 우측으로 2 Shift 하는 코드를 작성하시오.

배점 : 4점
18. 1, 3, 4, 7, 11, 18, 29, 47, 76, ... 형태로 숫자가 진행된다.
     40번째 숫자는 무엇일까 ?

#include <stdio.h>

int fib(int in1, int in2)
{
	return in1 + in2;
}

int main(void)
{
	int i, tmp;
	int in1 = 1, in2 = 3;

	for(i = 0; i < 38; i++)
	{
		tmp = in2;
		in2 = fib(in1, in2);
		in1 = tmp;
	}
	printf("40th num = %d\n", in2);
	return 0;
}
#endif
#if  0
배점 : 4점
19. 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ... 형태로 숫자가 진행된다.
    1 ~ 30번째까지의 수들로 홀수들의 합을 하고 짝수들의 합을 구한다.
    홀수들의 합 - 짝수들의 합의 결과를 출력하시오.

배점 : 2점
20. 3 by 3 행렬의 덧셈을 계산하는 프로그램을 작성하시오.

#include <stdio.h>

int arr_sum(int arr1[3][3], int arr2[3][3])
{
	int i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++)
			arr1[i][j] = arr1[i][j] + arr2[i][j];
	}
}

void m3x3_prn(int arr[3][3])
{
	int i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int arr1[3][3] = {{1, 3, 6}, {7, 1, 9}, {3, 7, 5}};
	int arr2[3][3] = {{3, 5, 7}, {9, 1, 8}, {5, 1, 2}};

	arr_sum(arr1, arr2);

	m3x3_prn(arr1);

	return 0;
}
#endif

#if 0
[ 복합문제 ]
배점 : 3점
21. 난수를 활용해서 Stack을 구성한다.
     (같은 숫자가 들어가지 않게 하고 20개 이상 넣는다
      이때 들어가는 숫자는 1 ~ 50사이의 숫자로 넣는다)

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

typedef struct _node{
	int data;
	struct _node *link;
}node;

node *get_node(int data)
{
	node *tmp;
	tmp = (node *)malloc(sizeof(node));
	tmp->link = NULL;
	tmp->data = data;
	return tmp;
}
void ins_stack(node **root, int data)
{
	if(!*root) *root = get_node(data);
	else {
		node *tmp;
		tmp = *root;
		*root = get_node(data);
		(*root)->link = tmp;
	}
}

void prn_stack(node **root)
{
	node *tmp = (*root);
	while(tmp->link)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->link;
	}	
}

int main(void)
{
	int i;
	node *root = 0;
	srand(time(NULL));

	for(i = 0; i < 20; i++)
		ins_stack(&root, rand() % 50 + 1);

	prn_stack(&root);

	return 0;
}
#endif

#if 0
배점 : 5점
22. 그 중에서 홀 수만 빼내서 AVL Tree를 구성하도록 한다.

배점 : 5점
23. 나머지(짝 수)는 Binary Tree로 구성한다.

배점 : 1점
24. Linux에서 vim Editor는 굉장히 사랑받는 Editor 중 하나다.
    여기서 7줄 복사해서 붙여넣고자 하는데 어떻게 해야 7줄을 복사 붙여넣기 할 수 있는가 ?

배점 : 2점
25. 프로그램을 최적화하여 컴파일 하는 옵션을 적고
    최적화하지 않고 디버깅 옵션을 넣어서 컴파일 하는 방법을 기술하시오.
#endif
