#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e7;
vector<vector<int> > graph;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	graph.resize(n + 1, vector<int>(n + 1, MAX));
	for (int i = 0; i < m; ++i) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1][v2] = graph[v2][v1] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (graph[i][k] + graph[k][j] < graph[i][j]) {
					graph[i][j] = graph[j][i] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	int k = 0;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int id;
		scanf("%d", &id);
		int sum = 0;
		double ans = 0;
		for (int j = 1; j <= n; ++j) {
			if (j != id)
				sum += graph[id][j];

			if (sum >= MAX)
				break;
		}

		if (sum < MAX)
			ans = (n - 1) * 1.0 / sum;

		printf("Cc(%d)=%.2f\n", id, ans);
	}
	return 0;
}