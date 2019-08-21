#include<bits/stdc++.h>
using namespace std;

const int MAX = 110;
int n, m;
vector<int> num, sum(MAX), pre(MAX), ans;

int dfs(int i, int aim) {
	int re = 0;
	if (aim < 0)
		return re = -1;
	else if (aim == 0)
		return re = 1;
	else {
		for (; i < n; ++i) {
			ans.push_back(num[i]);
			re = dfs(i + 1, aim - num[i]);
			if (re == 1)
				break;
			ans.pop_back();
			if (re < 0) {
				re = 0;
				break;
			}
		}
	}
	return re;
}

int main() {
	scanf("%d %d", &n, &m);
	num.reserve(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int number;
		scanf("%d", &number);
		if (number <= m) {
			sum += number;
			num.push_back(number);
		}
	}
	n = num.size();
	sort(num.begin(), num.end());

	int re = 0;
	if(sum >= m)
		re = dfs(0, m);

	if (re) {
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