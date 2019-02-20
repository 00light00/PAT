#include<bits/stdc++.h>
using namespace std;

const int MAX = 10010;
vector<int> graph[MAX];

int kcolor(int n) {
	unordered_set<int> color_set;
	vector<int> color, visit(n, 0);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int co;
		scanf("%d", &co);
		color_set.insert(co);
		color.push_back(co);
	}

	for (int i = 0; i < n; i++) {
		int co1 = color[i];
		for (auto it = graph[i].begin(); it != graph[i].end(); it++) {
			int co2 = color[*it];
			if (co1 == co2)
				return cnt;
		}
	}

	cnt = color_set.size();
	return cnt;
}

int main() {
	int n, m, k;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int re = 0;
		re = kcolor(n);
		if (re)
			printf("%d-coloring\n", re);
		else
			printf("No\n");
	}

	return 0;
}