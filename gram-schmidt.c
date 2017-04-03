#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VEC_MAX		3

void vec_init(float *v3)
{
	int i;
	float temp[10] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};

	for(i = 0; i < VEC_MAX; i++)
	{
		v3[i] = rand() % 3 + 3;
		v3[i] += temp[rand() % 10];
	}
}

void print_vec(float *v3)
{
	int i;

	for(i = 0; i < VEC_MAX; i++)
		printf("v3[%d] = %f\n", i, v3[i]);
	printf("\n");
}

void vec_add(float *x, float *y, float *r)
{
	int i;

	for(i = 0; i < VEC_MAX; i++)
		r[i] = x[i] + y[i];
}

void vec_sub(float *x, float *y, float *r)
{
	int i;

	for(i = 0; i < VEC_MAX; i++)
		r[i] = x[i] - y[i];
}

void vec_scalar(float *x, float rate, float *r)
{
	int i;

	for(i = 0; i < VEC_MAX; i++)
		r[i] = x[i] * rate;
}

float inner(float *x, float *y)
{
	int i;
	float tmp = 0.0;

	for(i = 0; i < VEC_MAX; i++)
		tmp += x[i] * y[i];

	return tmp;
}

// void col_A(float (*A)[3], float(*a)[3], int col)
// {
// 	int i;
// 	for(i = 0; i < 3; i++)
// 		a[0][i] = A[i][col];
// }

void col_A(float (*A)[3], float(*a), int col)
{
	int i;
	for(i = 0; i < 3; i++)
		a[i] = A[i][col];
}

void print_colA(float (*v3)[3])
{
	int i;

	for(i = 0; i < VEC_MAX; i++)
		printf("v3[0][%d] = %f\n", i, v3[0][i]);
	printf("\n");
}

void gram_schmidt(float (*A)[3], float(*q1), float(*q2), float(*q3))
{
	float r1[3] = {0};
	float r2[3] = {0};

	col_A(A, q1, 0);
	col_A(A, q2, 1);
	col_A(A, q3, 2);

	vec_scalar(q1, inner(q2, q1), r1);
	vec_sub(q2, r1, q2);

	vec_scalar(q1, inner(q3, q1), r1);
	vec_scalar(q2, inner(q3, q2), r2);
	vec_sub(q3, r1, q3);
	vec_sub(q3, r2, q3);

	print_vec(q1);
	print_vec(q2);
	print_vec(q3);
}

int main(void)
{
	float res;
	float A[3][3] = {1,2,4,0,0,5,0,3,6};
	float q1[3] = {0};		// float q1[1][3] = {0};
	float q2[3] = {0};
	float q3[3] = {0};

	srand(time(NULL));

	gram_schmidt(A, q1, q2, q3);

	return 0;
}