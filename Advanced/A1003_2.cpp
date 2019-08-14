#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e9;
typedef pair<int, int> pii;
int n, m, st, ed;
vector<int> rescueTeam, visit, dist, cnt, pcnt;
vector<vector<pii>> graph;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int st, int ed) {
	dist[st] = 0;
	cnt[st] = rescueTeam[st];
	pcnt[st] = 1;
	pq.push(pii(0, st));

	while (!pq.empty()) {
		pii now = pq.top();
		int nowid = now.second;
		pq.pop();
		if (!visit[nowid]) {
			visit[nowid] = 1;
			for (auto it = graph[nowid].begin(); it != graph[nowid].end(); ++it) {
				int nextid = it->second, dis = it->first;
				if (!visit[nextid]) {
					if (dist[nowid] + dis < dist[nextid]) {
						dist[nextid] = dist[nowid] + dis;
						cnt[nextid] = cnt[nowid] + rescueTeam[nextid];
						pcnt[nextid] = pcnt[nowid];
					}
					else if (dist[nowid] + dis == dist[nextid]) {
						cnt[nextid] = max(cnt[nextid], cnt[nowid] + rescueTeam[nextid]);
						pcnt[nextid] += pcnt[nowid];
					}
					pq.push(pii(dist[nextid], nextid));
				}
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d %d %d %d", &n, &m, &st, &ed);
	rescueTeam.resize(n);
	visit.resize(n);
	dist.resize(n, MAX);
	cnt.resize(n);
	pcnt.resize(n);
	graph.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &rescueTeam[i]);
	}
	for (int i = 0; i < m; ++i) {
		int c1, c2, dis;
		scanf("%d %d %d", &c1, &c2, &dis);
		graph[c1].push_back(pii(dis, c2));
		graph[c2].push_back(pii(dis, c1));
	}
	
	dijkstra(st, ed);

	printf("%d %d\n", pcnt[ed], cnt[ed]);
	return 0;
}