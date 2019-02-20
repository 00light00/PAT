#include<bits/stdc++.h>
using namespace std;

int direct[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int main() {
	int N, n, m;
	scanf("%d", &N);
	n = sqrt(N);
	for (; N%n != 0; n--) {};
	m = N / n;
	vector<int> num(N);
	vector<vector<int> > re(m, vector<int>(n));
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	sort(num.begin(), num.end(),greater<int>());

	int edge[4] = { n - 1,m - 1,0,0 };
	int x = 0, y = 0, di = 0;
	for (int i = 0; i < N; i++) {
		re[y][x] = num[i];
		int xx = x + direct[di][0];
		int yy = y + direct[di][1];
		if (0 <= xx && 0 <= yy && xx <= n - 1 && yy <= m - 1 && re[yy][xx] == 0) {
			x = xx;
			y = yy;
		}
		else {
			di = (di + 1) % 4;
			x += direct[di][0];
			y += direct[di][1];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j > 0)
				printf(" ");
			printf("%d", re[i][j]);
		}
		printf("\n");
	}
	return 0;
}