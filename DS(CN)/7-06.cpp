#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> v, int i,vector<int> & visit) {
	if (!visit[i]) {
		printf("%d ", i);
		visit[i] = 1;
		for (int p=0; p <v[i].size(); p++) {
			if (v[i][p]) {
				dfs(v, p, visit);
			}
		}
	}
}

void bfs(vector<vector<int>> v, int i,vector<int> & visit) {
	vector<int> queue;
	queue.push_back(i);
	visit[i] = 1;
	int p = 0;
	while (p < queue.size()) {
		int k = queue[p];
		printf("%d ", k);
		for (int m = 0; m < v[k].size(); m++) {
			if (v[k][m] && !visit[m]) {
				queue.push_back(m);
				visit[m] = 1;
			}
		}
		p++;
	}
}

int main() {
	int n, e;
	scanf("%d %d", &n, &e);
	vector<vector<int> > v(n, vector<int>(n));
	for (int i = 0; i < e; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[x][y] = v[y][x] = 1;
	}
	vector<int> visitdfs(n, 0);
	for (int i = 0; i < n; i++) {
		if (!visitdfs[i]) {
			printf("{ ");
			dfs(v, i, visitdfs);
			printf("}\n");
		}
	}
	vector<int> visitbfs(n, 0);
	for (int i = 0; i < n; i++) {
		if (!visitbfs[i]) {
			printf("{ ");
			bfs(v, i, visitbfs);
			printf("}\n");
		}
	}
	return 0;
}