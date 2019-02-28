#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 220;
int hap[MAX], visit[MAX], mincnt[MAX], minc[MAX], maxha[MAX], pre[MAX], cntlc[MAX];
vector<pii> graph[MAX];
priority_queue<pii, vector<pii>, greater<pii>> pq;
map<string, int> ci;
map<int, string> ic;

void dijkstra(string st, string dest) {
	while (!pq.empty())
		pq.pop();

	memset(visit, 0, sizeof(visit));
	memset(mincnt, 127, sizeof(mincnt));
	memset(minc, 127, sizeof(minc));
	memset(maxha, 0, sizeof(maxha));
	memset(cntlc, 0, sizeof(cntlc));

	int start = ci[st];
	minc[start] = 0;
	maxha[start] = 0;
	mincnt[start] = 0;
	cntlc[start] = 1;
	pq.push(make_pair(minc[start], start));

	while (!pq.empty()) {
		int city = pq.top().second;
		pq.pop();
		if (!visit[city]) {
			visit[city] = 1;
			for (auto it = graph[city].begin(); it != graph[city].end(); it++) {
				int othercity = it->first, cost = it->second, happy = hap[othercity];
				if (minc[city] + cost < minc[othercity]) {
					minc[othercity] = minc[city] + cost;
					maxha[othercity] = maxha[city] + happy;
					mincnt[othercity] = mincnt[city] + 1;
					pre[othercity] = city;
					cntlc[othercity] = cntlc[city];
					pq.push(make_pair(minc[othercity], othercity));
				}
				else if (minc[city] + cost == minc[othercity]) {
					cntlc[othercity] += cntlc[city];
					if (maxha[othercity] < maxha[city] + happy) {
						maxha[othercity] = maxha[city] + happy;
						mincnt[othercity] = mincnt[city] + 1;
						pre[othercity] = city;
					}
					else if (maxha[othercity] == maxha[city] + happy) {
						if (mincnt[city] + 1 < mincnt[othercity]) {
							mincnt[othercity] = mincnt[city] + 1;
							pre[othercity] = city;
						}
					}
				}
			}
		}
	}
}

void dfs(int city) {
	if (pre[city]) {
		dfs(pre[city]);
		printf("->");
	}
	printf("%s", ic[city].c_str());
}

int main() {
	int n, k;
	char st[5];
	scanf("%d %d %s", &n, &k, st);
	ci[st] = 1;
	ic[1] = st;
	for (int i = 2; i <= n; i++) {
		char city[5];
		int happy;
		scanf("%s %d", city, &happy);
		ci[city] = i;
		ic[i] = city;
		hap[i] = happy;
	}

	for (int i = 0; i < k; i++) {
		char city1[5], city2[5];
		int len;
		scanf("%s %s %d", city1, city2, &len);
		int ci1 = ci[city1], ci2 = ci[city2];
		graph[ci1].push_back(make_pair(ci2, len));
		graph[ci2].push_back(make_pair(ci1, len));
	}
	
	dijkstra(st,"ROM");

	int dest = ci["ROM"];
	printf("%d %d %d %d\n", cntlc[dest], minc[dest], maxha[dest], maxha[dest] / mincnt[dest]);
	dfs(dest);
	return 0;
}