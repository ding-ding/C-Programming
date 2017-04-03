#if 0
7. 1 ~ 1000사이에서 짝수와 홀수의 합을 각각 구하고
   짝수의 합으로 홀수의 합을 나눈 결과를 정수형으로 출력하라.


#include <stdio.h>

int main(void)
{
	int i;
	double e_sum, o_sum;

	for(i = 1; i <= 1000; i++)
	{
		if(i%2)
			e_sum += i;
		else 
			o_sum += i;
	}


	printf("odd = %f , even = %f , odd / even = %f\n", o_sum, e_sum, o_sum / e_sum);
	return 0;

}
#endif

#if 0
8. 7과 4이라는 2개의 정수를 입력받아 num1, num2에 저장하였다.
   num1 << num2, num1 >> num2의 값과
   num1과 num2의 and, or, xor bit 연산을 수행하는 프로그램을 작성하시오.


#include <stdio.h>

int main(void)
{
	int num1, num2;

	puts("insert number");
	scanf("%d %d", &num1, &num2);

	printf("num1 << num2 = %d  ", num1 << num2);
	printf("num1 >> num2 = %d\n", num1 >> num2);

	return 0;
}
#endif

#if 0
p 명령어 (point) point 명령어는 변수 값, 함수의 주소값도 볼 수 있다.
x 명령어는 메모리 특정 범위의 값들을 확인하는데 사용하는 명령어다.
#endif



#if 0
#include <stdio.h>
#define inc_each(x, y) { x++; y++; }

int main(void)
    {
        int x = 10, y = 5;

        if(x > y){
            inc_each(x, y);
        }
        else{
            x = y;
        }
        

        return 0;
    }
#endif

#if 0
13. 이중 for문을 사용하여 구구단을 작성해보시오.
#endif

#if 0
#include <stdio.h>


int main(void)
{
	int i, j;

	for(i = 1; i <= 9 ; i++)
	{
		for(j = 1; j <= 9; j++)
			printf("%d dan %d * %d = %d\n", i, i, j, i * j);
	}
}
#endif

#if 0
    #include <stdio.h>

    int main(void)
    {
        int number = 1;
        for(;;)
        {
            printf("number = %d\n", number);
            number += number;
            if(number == 1000)
                break;
        }
        return 0;
    }
#endif

#if 0
20. 20개의 배열에 rand()를 이용하여 무작위로 1 ~ 100까지의 값을 저장하는 프로그램을 작성하라.

21. 그리고 각 배열의 요소의 홀수들과 짝수들의 합을 구해 출력하라.

22. 홀수들의 합과 짝수들의 합을 곱하여 출력하라.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int i, num[20];
	int e_sum = 0, o_sum = 0;

	for(i = 0; i < 20; i++)
	{
		num[i] = rand() % 100 + 1;
		if(num[i] % 2)
			o_sum += num[i];
		else 
			e_sum += num[i];
	}
	printf("%d * %d = %d\n",o_sum, e_sum, o_sum * e_sum);

	return 0;
}

#endif

#if 0
23. 대문자를 입력하면 소문자가 나오도록
    소문자를 입력하면 대문자가 나오도록 프로그램을 작성하시오.


#include <stdio.h>
int main(void)
{
	char num;
	printf("insert abc  ");
	scanf("%c", &num);

	if(num > 64 || num < 97)
		printf("big num = %c\n", (char)num + 32);
	else if(num > 96 || num < 123)
		printf("small num = %c\n", (char)num - 32);
	else 
		printf("fuck\n");
	return 0;
}
#endif

#if 0
24-25 복합 문제

24. 어떤 정수에 값 13이 들어 있다.
    이것을 4중 포인터를 사용하여 표현해보라.

25. 4중 포인터를 사용하여 표현했다면
    현재 값인 13을 14로 증가시켜보자.
    (num++을 사용하지 말라)


#include <stdio.h>

int main(void) 
{
	int num = 13;
	int *p_num1 = &num;
	int **p_num2 = &p_num1;
	int ***p_num3 = &p_num2;
	int ****p_num4 = &p_num3;
	printf("num = %d\n", ****p_num4);
	(*p_num1)++;
	printf("num = %d\n", ****p_num4);	
	return 0;
}
#endif


#if 0
26. 행렬의 곱셈을 프로그램으로 작성하라.


#include <stdio.h>

int main(void)
{
	int i, j;

	for(i = 0; i < )
}

#endif
#if 0

27. 전역 변수와 지역 변수의 차이점에 대해 기술하시오.
전역변수는 어떤 함수 에서든 호출 이 가능 하나 지역변수는 해당함수에서만 호출이 가능하다

28. 정수형 변수 2개를 선언하고 서로 다른 값으로 초기화한다.
    이후에 포인터를 사용하여 2개의 값을 서로 교환해보라.

#include <stdio.h>

int main(void)
{
	int num1 = 9, num2 = 12;
	int *p_num1 = &num1;


	return 0;
}
#endif

#if 0
29. 임의의 구조체를 한 개 만들고 해당 구조체에 대한 변수 2개를 선언한 이후
    구조체의 멤버들에 적절한 값을 입력한 후 해당 값을 서로 교환해보라.

#include <stdio.h>
#include <malloc.h>

typedef struct _node{
	int num1;
	int num2;
}node;

int main(void)
{
	int tmp;
	node n = {10, 20};

	printf("before %d %d\n", n.num1, n.num2);

	tmp = n.num1;
	n.num1 = n.num2;
	n.num2 = tmp;

	printf("after %d %d\n", n.num1, n.num2);

	return 0;
}
#endif

#if 0
30. 아래 코드를 보고 화면에 출력될 결과를 예측하시오.

#include <stdio.h>

int main(void)
{
    int shortcut1 = 0, shortcut2 = 3, num = 9;

    if(shortcut1 && num++)
        shortcut1++;

    printf("%d, %d\n", shortcut1, num);

    if(shortcut1 || shortcut2)
        shortcut1++;

    printf("%d\n", shortcut1);

    if(shortcut1 && ++num)
        shortcut2--;

    printf("%d, %d, %d\n", shortcut1, num, shortcut2);

    return 0;
}
0 9
1
1 9 2

#endif

#if 0
31. 아래 코드를 보고 화면에 출력될 결과를 예측하시오.

#include <stdio.h>

int main(void)
{
    int i, j;
    int num1, num2, num3;
    int arr[2][6];
    int *arr_ptr[3] = {&num1, &num2, &num3};
    int (*p)[6] = arr;

    for(i = 0; i < 3; i++)
    {
        *arr_ptr[i] = i;
        printf("%d\n", *arr_ptr[i]);
    }
    for(i = 0; i < 2; i++)
        for(j = 0; j < 6; j++)
            arr[i][j] = (i + 1) * (j + 1) * 10;

    for(i = 0; i < 2; i++)
        printf("%d\n", *p[i]);

    return 0;
}
#endif

#if 0
10 20 30 40 50 60
20 40 60 80 100 120
10 20

32. 아래 코드를 보고 해당 프로그램이 어떻게 동작하는지 기술하시오.

#include <stdio.h>

int fib(int num)
{
    if(num == 1 || num == 2)
        return 1;
    else
        return fib(num - 1) + fib(num - 2);
}

int main(void)
{
    int result, final_val = 6;
    result = fib(final_val);
    printf("%d번째 항의 수는 = %d\n", final_val, result);
    return 0;
}

33. 임의의 값 x가 있는데, 이를 4096 단위로 정렬하고 싶다면 어떻게 해야할까 ?
    (힌트 : 4096 = 2^12)

34. 구조체를 사용하여 Stack을 구현해보시오.

35. char *str = "Pointer Is Very Importan"라는 문자열이 있다
    여기에 대문자가 총 몇 개 사용되었는지 세어보자

36. 포인터의 크기가 무엇에 따라 좌우되는지 기술하고 이유를 서술하시오.

37. int p[4]와 int (*p)[4]의 차이에 대해 기술하시오.

38. 함수 포인터를 사용하는 이유에 대해 기술하시오.

39. 아래의 선언을 보고 이것이 무엇인지 기술하시오.
    (인자는 무엇이고 반환형은 무엇인지 함수인지 함수 포인터인지 등등)

void (* signal(int signum, void (*handler)(int)))(int);

40. volatile 키워드의 용도는 무엇일까 ?
volatile로 선언된 변수는 외부적인 요인으로 그 값이 언제든지 바뀔 수 있음을 뜻한다. 
따라서 컴파일러는 volatile 선언된 변수에 대해서는 최적화를 수행하지 않는다. 
volatile 변수를 참조할 경우 레지스터에 로드된 값을 사용하지 않고 매번 메모리를 참조한다
#endif