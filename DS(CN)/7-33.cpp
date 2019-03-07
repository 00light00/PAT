#include<bits/stdc++.h>
using namespace std;

vector<int> visit, ans;
vector<set<int> > graph;
int n, len = 0;

void dfs(int s) {
	if (!visit[s]) {
		len++;
		visit[s] = 1;
		ans.push_back(s);
		for (auto it = graph[s].begin(); it != graph[s].end(); it++) {
			int p = *it;
			if (!visit[p]) {
				dfs(p);
				ans.push_back(s);
			}
		}
	}
	return;
}

int main() {
	int m, s;
	scanf("%d %d %d", &n, &m, &s);
	visit.resize(n + 1, 0), graph.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1].insert(v2);
		graph[v2].insert(v1);
	}

	dfs(s);

	for (auto it = ans.begin(); it != ans.end(); it++) {
		if (it != ans.begin())
			printf(" ");
		printf("%d", *it);
	}
	if (len != n)
		printf(" %d", 0);
	return 0;
}