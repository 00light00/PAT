#include<iostream>
#include <algorithm>
using namespace std;

const int MAX = 100010;
int num[MAX], n_max[MAX], n_min[MAX],re[MAX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		n_max[i] = n_min[i] = num[i];
	}
	for (int i = 1; i < n; i++) {
		if (n_max[i - 1] > n_max[i])
			n_max[i] = n_max[i - 1];
	}

	for (int i = n - 2; i >= 0; i--) {
		if (n_min[i + 1] < n_min[i])
			n_min[i] = n_min[i + 1];
	}

	int p_re = 0;
	for (int i = 0; i < n; i++) {
		if (n_max[i] == num[i] && n_min[i] == num[i]) {
			re[p_re++] = num[i];
		}
	}

	sort(re, re + p_re);
	printf("%d\n", p_re);
	for (int i = 0; i < p_re; i++) {
		if (i > 0)
			printf(" ");
		printf("%d", re[i]);
	}
	printf("\n");
	return 0;
}