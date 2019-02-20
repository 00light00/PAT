#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	sort(num.begin(), num.end());

	int l = 0, r = n - 1;
	int flag = 0;
	while (l < r) {
		if (num[l] + num[r] == m) {
			flag = 1;
			printf("%d %d\n", num[l], num[r]);
			break;
		}
		else if (num[l] + num[r] > m)
			r--;
		else
			l++;
	}
	if (!flag)
		printf("No Solution\n");
	return 0;
}