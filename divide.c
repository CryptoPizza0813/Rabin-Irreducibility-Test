#include "divide.h"

void divide(int* matrix1, int* matrix2, int k, int p, int n)
{
	int tmp = 0;
	for (int i = 0; i < k - n; i++)
	{
		tmp = matrix1[i];

		for (int j = 0; j < n + 1; j++)
		{
			matrix1[i + j] = (matrix1[i + j] - tmp * matrix2[j]) % p;
		}
		/*
		for (int j = 0; j < k + 1; j++)
		{P
			printf(" %d", matrix1[j]);
		}
		printf("\n");
		*/
	}


}

void divide1(int* matrix1, int* matrix2, int k, int p, int n, int tmp1, int tmp2)
{
	// printf("i am divide 1\n");
	int tmp = 0;
	for (int i = 0; i <= tmp1 - tmp2; i++)
	{
		tmp = matrix1[k + 1 - tmp1 + i];

		for (int j = 0; j < tmp2; j++)
		{
			matrix1[k + 1 - tmp1 + i + j] = ((matrix2[n + 1 - tmp2] * matrix1[k + 1 - tmp1 + i + j] - tmp * matrix2[n + 1 - tmp2 + j]) + p) % p;
		}
	}
	/*
	printf("GF :");
	for (int j = 0; j < k + 1; j++)
	{
		printf(" %d", matrix1[j]);
	}
	printf("\n");
	*/

}

void divide2(int* matrix1, int* matrix2, int k, int p, int n, int tmp1, int tmp2)
{
	// printf("i am divide 2\n");





	int tmp = 0;
	for (int i = 0; i <= tmp2 - tmp1; i++)
	{
		tmp = matrix1[n + 1 - tmp2 + i];

		for (int j = 0; j < tmp1; j++)
		{
			matrix1[n + 1 - tmp2 + i + j] = ((matrix1[n + 1 - tmp2 + i + j] * matrix2[k + 1 - tmp1] - tmp * matrix2[k + 1 - tmp1 + j]) + p) % p;
		}

	}
	/*
	printf("f :");
	for (int j = 0; j < n + 1; j++)
	{
		printf(" %d", matrix1[j]);
	}
	printf("\n");
	*/
}
