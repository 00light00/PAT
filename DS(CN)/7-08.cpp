#include<bits/stdc++.h>
using namespace std;

const int MAX = 10010;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int> > graph(n + 1, vector<int>(n + 1, MAX));
	for (int i = 0; i < m; ++i) {
		int n1, n2, val;
		scanf("%d %d %d", &n1, &n2, &val);
		graph[n1][n2] = graph[n2][n1] = val;
	}
	//Floyd
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i != j && graph[i][k] + graph[k][j] < graph[i][j]) {
					graph[i][j] = graph[j][i] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	//Find minmax;

	int minmax = MAX;
	int re_id = 0;
	for (int i = 1; i <= n; ++i) {
		int max = 0;
		for (int j = 1; j <= n; ++j) {
			if (i != j) {
				max = graph[i][j] > max ? graph[i][j] : max;
			}
		}
		if (max == MAX) {
			minmax = MAX;
			re_id = 0;
			break;
		}
		if (max < minmax) {
			re_id = i;
			minmax = max;
		}
	}
	if (re_id) {
		printf("%d %d\n", re_id, minmax);
	}
	else {
		printf("%d\n");
	}
	return 0;
}