#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> cnt(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		cnt[abs(i - tmp)]++;
	}
	for (int i = n; i >= 0; i--) {
		if (cnt[i]>1)
			printf("%d %d\n", i, cnt[i]);
	}
	return 0;
}