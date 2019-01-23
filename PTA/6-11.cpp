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

void swap(ElementType *a, ElementType *b)
{
	ElementType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int quickfound(ElementType A[], int l, int r) 
{
	ElementType tmp = A[l];
	while (l < r) {
		while (tmp < A[r] && l < r)
		{
			r--;
		}
		swap(&A[l], &A[r]);
		while (A[l] < tmp && l < r)
		{
			l++;
		}
		swap(&A[l], &A[r]);
	}
	return l;
}

ElementType Median(ElementType A[], int N)
{
	int l = 0, r = N - 1;
	int p = quickfound(A, l, r);
	while (p != N / 2) 
	{
		if (p < N / 2)
			l = p + 1;
		else
			r = p - 1;
		p = quickfound(A, l, r);
	}
	return A[N / 2];
}