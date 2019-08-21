//spfa * k

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e7;
typedef long long ll;
typedef pair<int, int> pii;
vector<vector<int> > graph;

ll djikstra(int id, int n) {
	vector<int> dis(n + 1, MAX), inque(n + 1);
	queue<int> que;
	dis[id] = 0;
	que.push(id);
	inque[id] = 1;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		inque[now] = 0;
		for (auto it = graph[now].begin(); it != graph[now].end(); ++it) {
			int nxt = *it;
			if (!inque[nxt]) {
				if (dis[now] + 1 < dis[nxt]) {
					dis[nxt] = dis[now] + 1;
					que.push(nxt);
				}
			}
		}
	}

	ll re = 0;
	for (int i = 1; i <= n; ++i) {
		re += dis[i];
		if (re >= MAX)
			break;
	}
	return re;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	graph.resize(n + 1);
	for (int i = 0; i < m; ++i) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	int k = 0;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int id;
		scanf("%d", &id);
		ll sum = djikstra(id, n);
		double ans = 0;

		if (sum < MAX)
			ans = (n - 1) * 1.0 / sum;

		printf("Cc(%d)=%.2f\n", id, ans);
	}
	return 0;
}