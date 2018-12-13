#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> score(m, 0), judge(m, 0);
	for (int i = 0; i < m; i++) {
		scanf("%d", &score[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &judge[i]);
	}

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			int ans;
			scanf("%d", &ans);
			if (ans == judge[j])
				sum += score[j];
		}
		printf("%d\n", sum);
	}
	return 0;
}