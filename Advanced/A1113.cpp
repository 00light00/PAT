#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	sort(num.begin(), num.end());

	long long sum = 0;
	for (int i = 0; i < n / 2; i++) {
		sum -= num[i];
	}
	for (int i = n / 2; i < n; i++) {
		sum += num[i];
	}

	printf("%d %d\n", n % 2, sum);
	return 0;
}