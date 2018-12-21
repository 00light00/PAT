#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> mooncake_cnt(n, 0);
	int cnt_max = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int cnt;
			scanf("%d", &cnt);
			mooncake_cnt[j] += cnt;
			cnt_max = cnt_max < mooncake_cnt[j] ? mooncake_cnt[j] : cnt_max;
		}
	}
	printf("%d\n", cnt_max);
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (mooncake_cnt[i] == cnt_max) {
			if (flag) {
				printf(" ");
			}
			else
				flag = 1;
			printf("%d", i + 1);
		}
	}
	printf("\n");

	return 0;
}