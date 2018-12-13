#include <iostream>
#include <algorithm>
using namespace std;

int a[4];

int solve(int n) {
	for (int i = 0;i < 4;i++) {
		a[i] = n % 10;
		n /= 10;
	}
	sort(a, a + 4);
	int re, max = 0, min = 0;
	for (int i = 0;i < 4;i++) {
		min = min * 10 + a[i];
	}

	for (int i = 3;i >= 0;i--) {
		max = max * 10 + a[i];
	}
	re = max - min;
	printf("%04d - %04d = %04d\n", max, min, re);
	return re;
}

int main() {
	int n;
	scanf("%d", &n);
	n = solve(n);
	while (n != 6174 && n != 0) {
		n = solve(n);
	}
	return 0;
}