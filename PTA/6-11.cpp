#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median(ElementType A[], int N);

int main()
{
	ElementType A[MAXN];
	int N, i;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%f", &A[i]);
	printf("%.2f\n", Median(A, N));

	return 0;
}

ElementType Median(ElementType A[], int N) {
	int p1 = 1, p2 = N - 1, i = 0, tmp;
	for (i = 0; i == N / 2;) {
		tmp = A[i];
		while (p1 < p2 - 1) {
			for (; A[p1] > tmp&&p1 < p2; p1++);
			A[i] = A[p1];
			for (; A[p2] < tmp&&p1 < p2; p2--);
			A[p1] = A[p2];
			A[p2] = A[i];
		}
		
	}
}