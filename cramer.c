#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL		3
#define ROW		3

void init_matrix(float (*A)[3], float (*X)[3], float (*Y)[3], float (*Z)[3], float (*S))
{
	int i, j;

	for(i = 0; i < ROW; i++)
		for(j = 0; j < COL; j++)
		{
			if(j == 0)
				X[i][j] = S[i];
			else
				X[i][j] = A[i][j];
			if(j == 1)
				Y[i][j] = S[i];
			else
				Y[i][j] = A[i][j];
			if(j == 2)
				Z[i][j] = S[i];
			else 
				Z[i][j] = A[i][j];
		}
}

void print_mat(float (*A)[3])
{
	int i, j;

	for(i = 0; i < ROW; i++)
		for(j = 0; j < COL; j++)
			printf("res[%d][%d] = %f\n", i, j, A[i][j]);
	printf("\n");
}

float det(float (*A)[3])
{
	float tmp = 0.0;

	tmp = (A[0][0] * A[1][1] * A[2][2] + A[0][1] * A[1][2] * A[2][0] + A[0][2] * A[1][0] * A[2][1] )
			- (A[0][0] * A[1][2] * A[2][1] + A[0][1] * A[1][0] * A[2][2] + A[0][2] * A[1][1] * A[2][0]);

	return tmp;
}

int main(void)
{
	float A[3][3] = {4, 5, 0, 2, 1, 2, 1, 5, 2};
	float X[3][3] = {0};
	float Y[3][3] = {0};
	float Z[3][3] = {0};
	float S[3] = {2, 3, 1};

	float detA, detX, detY, detZ;

	init_matrix(A, X, Y, Z, S);

	detA = det(A);
	detX = det(X);
	detY = det(Y);
	detZ = det(Z);

	print_mat(A);
	print_mat(X);
	print_mat(Y);
	print_mat(Z);

	printf("x = |X| / |A| = %f / %f = %f\n", detX, detA, detX / detA);
	printf("y = |Y| / |A| = %f / %f = %f\n", detY, detA, detY / detA);
	printf("z = |Z| / |A| = %f / %f = %f\n", detZ, detA, detZ / detA);

	return 0;
}
