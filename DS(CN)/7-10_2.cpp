#include<bits/stdc++.h>
using namespace std;


typedef pair<int, int> pii;
vector<vector<pii> > graph;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	graph.resize(n + 1);
	vector<int> visit(n + 1, 0);
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	for (int i = 0; i < m; i++) {
		int v1, v2, cost;
		scanf("%d %d %d", &v1, &v2, &cost);
		graph[v1].push_back(pii(cost, v2));
		graph[v2].push_back(pii(cost, v1));
	}

	int cnt = 0, sum = 0;
	pq.push(pii(0, 1));

	while (!pq.empty()) {
		int v = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (!visit[v]) {
			visit[v] = 1;
			sum += cost;
			cnt++;
			if (cnt == n)
				break;
			for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
				int v2 = it->second, cost2 = it->first;
				if(!visit[v2])
					pq.push(pii(cost2, v2));
			}
		}
	}

	if (cnt != n) {
		sum = -1;
	}
	printf("%d\n", sum);
	return 0;
}