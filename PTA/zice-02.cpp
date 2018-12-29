#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> check(n + 10, 1);
	for (int i = 2; i <= n; i++) {
		if(check[i])
			for (int j = 2; j*i <= n; j++) {
				check[i*j] = 0;
			}
	}

	int cnt = 0;
	for (int i = 3; i + 2 <= n; i += 2) {
		if (check[i] && check[i + 2])
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}