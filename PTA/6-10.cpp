#include <stdio.h>

void Print_Factorial(const int N);

int main()
{
	int N;

	scanf("%d", &N);
	Print_Factorial(N);
	return 0;
}

void Print_Factorial(const int N)
{
	int num[5000] = { 1 };
	if (N >= 1000 || N < 0) {
		printf("Invalid input\n");
	}
	else {

		int cnt, i, j;
		for (j = 1; j <= N; j++) {
			int add = 0;
			for (i = 0; i < 5000; i++) {
				int tmp = num[i] * j + add;
				num[i] = tmp % 10;
				add = tmp / 10;
			}
		}

		int flag = 0;
		for (i = 4999; i >= 0; i--) {
			if (flag||num[i]) {
				flag = 1;
				printf("%d", num[i]);
			}
		}
		printf("\n");
	}
}