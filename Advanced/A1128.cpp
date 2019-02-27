#include<bits/stdc++.h>
using namespace std;

int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int n;
		scanf("%d", &n);
		vector<int> queens(n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &queens[j]);
		}

		int flag = 1;
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < j; l++) {
				int dis = abs(queens[j] - queens[l]);
				if (dis == 0 || dis == j - l) {
					flag = 0;
					break;
				}
			}
			if (!flag)
				break;
		}

		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}