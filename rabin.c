#include "rabin.h"


void test()
{
	int check = 0;
	int p = 0; int n = 0; int a = 0; int tmp = 0; int b = 0; int c = 0;

	printf("enter prime number : ");
	scanf("%d", &p);
	printf("enter degree : ");
	scanf("%d", &n);

	int k = 1;

	for (int i = 0; i < n; i++)
	{
		k *= p;
	}

	int* gf = (int*)calloc(sizeof(int), (k + 1));

	int cnt = 0;

	// n의 약수들 계산 시작
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			gf[cnt] = i;
			cnt += 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("gf[%d] = %d\n", i, gf[i]);
	}
	printf("cnt = %d\n", cnt); // cnt는 n의 약수의 개수이고 gf[i]들은 각각 n의 약수가 들어가있다.

	for (int i = 0; i < cnt; i++)
	{
		//gf[i]의 숫자를 p의  gf[i]제곱으로 바꿔줘야 한다.
		tmp = 1;
		for (int j = 0; j < gf[i]; j++)
		{
			tmp *= p;
		}
		gf[i] = tmp;
	}

	for (int i = 0; i < n; i++)
	{
		printf("gf[%d] = %d\n", i, gf[i]);
	}


	int* f = (int*)calloc(sizeof(int), (n + 1));
	int* f1 = (int*)calloc(sizeof(int), (n + 1));
	int* GF = (int*)calloc(sizeof(int), (k + 1));

	printf("enter polynomial which want to check :\n");
	for (int i = 0; i < n + 1; i++)
	{
		scanf("%d", &f[i]);
	}
	printf("\n");



	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			f1[j] = f[j];
		}




		for (int j = 0; j < k + 1; j++)
		{
			GF[j] = 0;
		}

		GF[k - gf[i]] = 1;
		GF[k - 1] = -1 % p;

		while (1)
		{
			int tmp1 = k + 1; int tmp2 = n + 1;

			for (int m = 0; m < k + 1; m++)
			{
				if (GF[m] == 0)
				{
					tmp1 -= 1;
				}
				else
				{
					break;
				}
			}

			for (int m = 0; m < n + 1; m++)
			{
				if (f1[m] == 0)
				{
					tmp2 -= 1;
				}
				else
				{
					break;
				}
			}
			// printf("tmp1 = %d, tmp2 = %d\n", tmp1, tmp2);


			for (int m = 0; m < k + 1; m++)
			{
				GF[m] = (GF[m] + p) % p;
			}
			for (int m = 0; m < n + 1; m++)
			{
				f1[m] = (f1[m] + p) % p;
			}





			if (tmp1 >= tmp2)
			{
				divide1(GF, f1, k, p, n, tmp1, tmp2);
			}
			else
			{
				divide2(f1, GF, k, p, n, tmp1, tmp2);
			}


			b = 0; c = 0;
			for (int m = 0; m < k ; m++)
			{
				b = b + ((GF[m] + p) % p);
			}
			for (int m = 0; m < n ; m++)
			{
				c = c + ((f1[m] + p) % p);
			}

			
			if ((b == 0 && GF[k] != 0) || (c == 0 && f1[n] != 0))
			{
				printf("continue!\n");
				break;
			}
			else if (b != 0 && c != 0)
			{
				continue;
			}
			else
			{
				printf("a it's reducible!\n");
				
				printf("GF :");
				for (int z = 0; z < k + 1; z++)
				{
					printf(" %d", GF[z]);
				}
				printf("\n");

				printf("f :");
				for (int z = 0; z < n + 1; z++)
				{
					printf(" %d", f1[z]);
				}
				printf("\n");




				check = 1;
				break;
			}
		}

		if (check == 1)
		{
			break;
		}
	}

	/********************************************************/
	for (int i = 0; i < k + 1; i++)
	{
		GF[i] = 0;
	}

	GF[0] = 1;
	GF[k - 1] = -1 % p;


	divide(GF, f, k, p, n);
	/*
	for (int i = 0; i < k + 1; i++)
	{
		printf(" %d", GF[i]);
	}
	printf("\n");
	*/
	a = 0;

	for (int j = 0; j < k + 1; j++)
	{
		if (GF[j] == 0)
			a += 1;
	}


	/*
	printf(" a = %d, k+1 = %d\n", a, k + 1);

	for (int i = 0; i < n + 1; i++)
	{
		printf("%dx^%d ", f[i], n - i);
	}
	*/

	printf("\n");
	if (n == 1)
	{
		printf("it's irreducible\n");
	}
	else
	{
		if (check != 1)
		{
			if (a == k + 1)
			{
				printf("b it`s irreducible\n");
			}
			else
			{
				printf("it`s reducible\n");
			}
		}
	}
	

	printf("\n");


	free(gf);
	free(GF);
	free(f);
	free(f1);
}

void make()
{
	int check1 = 0;
	int p = 0; int n = 0; int a = 0; int tmp = 0; int b = 0; int c = 0;

	srand((unsigned)time(NULL));

	printf("enter prime number : ");
	scanf("%d", &p);
	printf("enter it's degree : ");
	scanf("%d", &n);

	int k = 1;

	for (int i = 0; i < n; i++)
	{
		k *= p;
	}

	int* gf = (int*)calloc(sizeof(int), (k + 1));

	int cnt = 0;

	// n의 약수들 계산 시작
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			gf[cnt] = i;
			cnt += 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("gf[%d] = %d\n", i, gf[i]);
	}
	printf("cnt = %d\n", cnt); // cnt는 n의 약수의 개수이고 gf[i]들은 각각 n의 약수가 들어가있다

	for (int i = 0; i < cnt; i++)
	{
		//gf[i]의 숫자를 p의  gf[i]제곱으로 바꿔줘야 한다.
		tmp = 1;
		for (int j = 0; j < gf[i]; j++)
		{
			tmp *= p;
		}
		gf[i] = tmp;
	}

	for (int i = 0; i < n; i++)
	{
		printf("gf[%d] = %d\n", i, gf[i]);
	}


	int* f = (int*)calloc(sizeof(int), (n + 1));
	int* f1 = (int*)calloc(sizeof(int), (n + 1));
	int* GF = (int*)calloc(sizeof(int), (k + 1));


	while (1)
	{
		f[0] = 1;
		for (int i = 1; i < n + 1; i++)
		{
			f[i] = (rand() + p) % p;
		}

		for (int i = 0; i < n + 1; i++)
		{
			printf("%d ", f[i]);
		}
		printf("\n");

		for (int i = 0; i < cnt; i++)
		{
			for (int j = 0; j < n + 1; j++)
			{
				f1[j] = f[j];
			}

			for (int j = 0; j < k + 1; j++)
			{
				GF[j] = 0;
			}

			GF[k - gf[i]] = 1;
			GF[k - 1] = -1 % p;

			while (1)
			{
				int tmp1 = k + 1; int tmp2 = n + 1;

				for (int m = 0; m < k + 1; m++)
				{
					if (GF[m] == 0)
					{
						tmp1 -= 1;
					}
					else
					{
						break;
					}
				}

				for (int m = 0; m < n + 1; m++)
				{
					if (f1[m] == 0)
					{
						tmp2 -= 1;
					}
					else
					{
						break;
					}
				}
				// printf("tmp1 = %d, tmp2 = %d\n", tmp1, tmp2);


				for (int m = 0; m < k + 1; m++)
				{
					GF[m] = (GF[m] + p) % p;
				}
				for (int m = 0; m < n + 1; m++)
				{
					f1[m] = (f1[m] + p) % p;
				}





				if (tmp1 >= tmp2)
				{
					divide1(GF, f1, k, p, n, tmp1, tmp2);
				}
				else
				{
					divide2(f1, GF, k, p, n, tmp1, tmp2);
				}


				b = 0; c = 0;
				for (int m = 0; m < k ; m++)
				{
					b = b + ((GF[m] + p) % p);
				}
				for (int m = 0; m < n ; m++)
				{
					c = c + ((f1[m] + p) % p);
				}

				if ((b == 0 && GF[k] != 0) || (c == 0 && f1[n] != 0))
				{
					break;
				}
				else if (b != 0 && c != 0)
				{
					continue;
				}
				else
				{
					check1 = 1;
					break;
				}
			}

			if (check1 == 1)
			{
				break;
			}
		}

		/********************************************************/
		for (int i = 0; i < k + 1; i++)
		{
			GF[i] = 0;
		}

		GF[0] = 1;
		GF[k - 1] = -1 % p;


		divide(GF, f, k, p, n);
		/*
		for (int i = 0; i < k + 1; i++)
		{
			printf(" %d", GF[i]);
		}
		printf("\n");
		*/
		a = 0;

		for (int j = 0; j < k + 1; j++)
		{
			if (GF[j] == 0)
				a += 1;
		}


		/*
		printf(" a = %d, k+1 = %d\n", a, k + 1);

		for (int i = 0; i < n + 1; i++)
		{
			printf("%dx^%d ", f[i], n - i);
		}
		*/

		printf("%d\n",n);

		if (a == k + 1)
		{
			printf("it`s irreducible\n");
			break;
		}
		else
		{
			printf("it`s reducible\n");
		}
	}

	for (int i = 0; i < n + 1; i++)
	{
		printf("%d ", f[i]);
	}
	printf("\n");

	free(gf);
	free(GF);
	free(f);
	free(f1);
}