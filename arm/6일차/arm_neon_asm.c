#include <stdio.h>

int main(void)
{
	int i;
	float arr[5] = {5.7, 2.1, 7.2, 3.4};

	register float *r4 asm("r4") = NULL;

	r4 = arr;

	for(i = 0; i < 4; i++)
		printf("arr[%d] = %f\n", i, arr[i]);

	asm volatile("vldr s1, [r4]\n"
				"vldr s2, [r4, #4]\n"
				"vldr s3, [r4, #8]\n"
				"vldr s4, [r4, #12]\n"
				"vadd.f32 s1, s1, s2\n"
				"vadd.f32 s2, s2, s3\n"
				"vadd.f32 s3, s3, s4\n"
				"vadd.f32 s4, s4, s1\n"
				"vstr s1, [r4]\n"
				"vstr s2, [r4, #4]\n"
				"vstr s3, [r4, #8]\n"
				"vstr s4, [r4, #12]\n");

	printf("\n");

	for(i = 0; i < 4; i++)
		printf("arr[%d] = %f\n", i, arr[i]);

	return 0;	
}