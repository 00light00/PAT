#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 505;
vector<pii> graph[MAX];
priority_queue<pii, vector<pii>, greater<pii> > pq;
int cnt[MAX];
int mind[MAX];
int visit[MAX];
int maxc[MAX];
int num[MAX];

void dijstra(int s, int e, int n, int m) {
	while (!pq.empty())
		pq.pop();
	memset(mind, 127, sizeof(mind));

	mind[s] = 0;
	maxc[s] = cnt[s];
	num[s] = 1;
	pq.push(make_pair(mind[s], s));

	while (!pq.empty()) {
		int city = pq.top().second;
		pq.pop();
		if (!visit[city]) {
			visit[city] = 1;
			for (auto it = graph[city].begin(); it != graph[city].end(); it++) {
				int p = it->first, len = it->second;
				if (mind[p] > mind[city] + len) {
					mind[p] = mind[city] + len;
					pq.push(make_pair(mind[p], p));
					maxc[p] = maxc[city] + cnt[p];
					num[p] = num[city];
				}
				else if (mind[p] == mind[city] + len) {
					num[p] += num[city];
					if (maxc[p] < cnt[p] + maxc[city]) {
						maxc[p] = maxc[city] + cnt[p];
					}
				}
			}
		}
	}
}



int main() {
	int n, m, s, e;
	scanf("%d %d %d %d", &n, &m, &s, &e);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cnt[i]);
	}
	for (int i = 0; i < m; i++) {
		int st, en, len;
		scanf("%d %d %d", &st, &en, &len);
		graph[st].push_back(make_pair(en, len));
		graph[en].push_back(make_pair(st, len));
	}
	dijstra(s, e, n, m);
	memset(visit, 0, sizeof(visit));
	printf("%d %d", num[e], maxc[e]);
	return 0;
}