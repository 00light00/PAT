#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

const int MAX = 10010;
int matrix[MAX][101];
int num[MAX];

int main() {
	int N, n, m;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);
	sort(num, num + N,greater<int>());

	n = sqrt(N);
	for (; N%n; n--);
	m = N / n;
	int line_t = 0, line_d = m - 1, row_l = 0, row_r = n - 1;
	for (int i = 0; i < N;) {
		for (int j = row_l; j <= row_r&& i < N; j++)
			matrix[line_t][j] = num[i++];
		line_t++;
		for (int j = line_t; j <= line_d&& i < N; j++)
			matrix[j][row_r] = num[i++];
		row_r--;
		for (int j = row_r; j >= row_l&& i < N; j--)
			matrix[line_d][j] = num[i++];
		line_d--;
		for (int j = line_d; j >= line_t&& i < N; j--)
			matrix[j][row_l] = num[i++];
		row_l++;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j > 0)
				printf(" ");
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}