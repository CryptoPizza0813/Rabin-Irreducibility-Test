#include "rabin.c"

int main()
{
	int z = 0;

	while (1)
	{
		system("cls");
		printf("Choose\n1. rabin irreducibility test\n2. make random irreducible polynomial\n3. exit program\n");
		system("pause");

		scanf("%d", &z);

		system("cls");


		if (z == 1)
		{
			test();
			system("pause");
		}
		else if (z == 2)
		{
			make();
			system("pause");
		}
		else
		{
			printf("Thanks for using me.\n");
			break;
		}
	}

	return 0;
}