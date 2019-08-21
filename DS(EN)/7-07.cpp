#include<bits/stdc++.h>
using namespace std;

const int MAX = 1001;
vector<int> result(MAX), input(MAX);
void cbst(int L, int R, int n);
int getleft(int n);

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
	sort(input.begin(), input.begin() + n);

	cbst(0, n - 1, 0);

	for (int i = 0; i < n; i++) {
		if (i > 0)
			printf(" ");
		printf("%d", result[i]);
	}
	return 0;
}

void cbst(int L, int R, int reroot) {
	int cnt = R - L + 1;
	if (cnt == 0)
		return;
	int l = getleft(cnt);
	result[reroot] = input[L + l];
	cbst(L, L + l - 1, 2 * reroot + 1);
	cbst(L + l + 1, R, 2 * reroot + 2);
}

int getleft(int n) {
	int re = 0, h = log2(n + 1);
	int x = n - pow(2, h) + 1;
	x = x < pow(2, h - 1) ? x : pow(2, h - 1);
	re = x + pow(2, h - 1) - 1;
	return re;
}