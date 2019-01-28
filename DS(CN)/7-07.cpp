#include<bits/stdc++.h>
using namespace std;

const int cnt = 6;

int bfs(vector<vector<int>> v, int n, int i) {
	vector<int> visit(n + 1, 0), queue;
	queue.reserve(n + 1);
	queue.push_back(i);
	visit[i] = 1;
	int re = 0, count = 0;
	auto p = queue.begin(), cp = p;
	while (p != queue.end()) {
		int val = *p;
		re++;
		for (auto val_p = v[val].begin(); val_p != v[val].end(); val_p++) {
			if (!visit[*val_p]) {
				queue.push_back(*val_p);
				visit[*val_p] = 1;
			}
		}
		if (cp == p) {
			cp = queue.end() - 1;
			count++;
		}
		if (count > cnt)
			break;
		p++;
	}
	return re;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int> > v(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		int num = bfs(v, n, i);
		printf("%d: %.2f%%\n", i, 100.0*num / n);
	}
	return 0;
}