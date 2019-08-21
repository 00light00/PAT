#include<bits/stdc++.h>
using namespace std;

const int MAX = 110;
vector<int> num, sum(MAX), ans;
vector<vector<int>> pre;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	num.resize(n);
	pre.resize(n, vector<int>(MAX));
	sum[0] = 1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num[i]);
	}
	sort(num.begin(), num.end());

	for (int i = n-1; i >= 0; --i) {
		int now = num[i];
		for (int j = MAX - 1; j >= now; --j) {
			if (sum[j - now]) {
				sum[j] = 1;
				pre[i][j] = 1;
			}
		}
	}

	if (sum[m]) {
		int p = m;
		for (int i = 0; i < n; ++i) {
			if (pre[i][p]) {
				ans.push_back(num[i]);
				p = p - num[i];
			}
		}
	}
	
	if (ans.size()) {
		for (int i = 0; i < ans.size(); ++i) {
			if (i)
				printf(" ");
			printf("%d", ans[i]);
		}
	}
	else {
		printf("No Solution\n");
	}
	return 0;
}