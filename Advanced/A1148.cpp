#include<bits/stdc++.h>
using namespace std;

const int MAX = 110;

int check(vector<int> player, int n, int i, int j) {
	int re = 0;
	int cntw = 0, cntm = 0;
	for (int k = 1; k <= n; k++) {
		int id = abs(player[k]);
		if ((player[k] > 0 && (id == i || id == j)) ||
			(player[k] < 0 && id != i && id != j)) {
			if (k == i || k == j)
				cntw++;
			else
				cntm++;
		}
	}
	if (cntw == 1 && cntm == 1)
		re = 1;
	return re;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> player(n+1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &player[i]);
	}

	int flag = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (check(player, n, i, j)) {
				printf("%d %d\n", i, j);
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}

	if (!flag)
		printf("No Solution\n");

	return 0;
}