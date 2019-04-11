#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<int> cnt, TopOrder;
vector<vector<pii> > graphlist;
vector<vector<int> > pre;
vector<pii> key;
int n, m;

void dfspre(int v) {
	if (v) {
		for (auto i : pre[v]) {
			dfspre()
		}
		key.push_back(v);
	}
	return;
}

int top() {
	int re = 0;
	int ptop = 0, front = 0;
	int maxtime = 0, maxv = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			TopOrder.push_back(i);
			front++;
		}
	}

	while (ptop < front) {
		int v = TopOrder[ptop++];
		for (auto it = graphlist[v].begin(); it != graphlist[v].end(); it++) {
			int nextv = it->first, time = it->second + pre[v].second;
			if (time > pre[nextv].second) {
				pre[nextv].second = time;
				pre[nextv].first = v;
			}
			else if (time == pre[nextv].second && v < pre[nextv].first) {
				pre[nextv].first = v;
			}
			if (maxtime <= time) {
				maxtime = time;
				maxv = nextv;
			}
			cnt[nextv]--;
			if (cnt[nextv] == 0) {
				TopOrder.push_back(nextv);
				front++;
			}
		}
	}
	if (ptop == n) {
		re = pre[maxv].second;
		dfspre(maxv);
	}
	return re;
}

int main() {
	scanf("%d %d", &n, &m);
	cnt.resize(n + 1, 0);
	graphlist.resize(n + 1);
	pre.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int v1, v2, time;
		scanf("%d %d %d", &v1, &v2, &time);
		cnt[v2]++;
		graphlist[v1].push_back(pii(v2, time));
	}

	int totaltime = top();
	printf("%d\n", totaltime);
	if (totaltime) {
		int num = key.size();
		for (int i = 1; i < num; i++) {
			printf("%d->%d\n", key[i - 1], key[i]);
		}
	}
	return 0;
}