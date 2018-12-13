#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int>cnt(3*n, 0);
	for (int i = 1; i <= n; i++)
		cnt[i / 2 + i / 3 + i / 5]++;
	int re = 0;
	for (int i = 0; i < 3*n; i++) {
		if (cnt[i])
			re++;
	}
	printf("%d\n", re);

	return 0;
}