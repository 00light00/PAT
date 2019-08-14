#include<bits/stdc++.h>
using namespace std;

struct node {
	vector<int> child;
	int level;
};
vector<node> tree;
vector<int> ans;
queue<int> que;

void bfs() {
	que.push(01);
	int level = 1, cnt = 0;
	tree[1].level = 0;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		if (tree[now].level == level) {
			level++;
			ans.push_back(cnt);
			cnt = 0;
		}
		if (tree[now].child.empty()) {
			cnt++;
		}
		else {
			for (auto it = tree[now].child.begin(); it != tree[now].child.end(); ++it) {
				int next = *it;
				tree[next].level = level;
				que.push(next);
			}
		}
	}
	ans.push_back(cnt);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	tree.resize(n + 10);
	for (int i = 0; i < m; ++i) {
		int id, k;
		scanf("%d %d", &id, &k);
		tree[id].child.resize(k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &tree[id].child[j]);
		}
	}

	bfs();

	for (auto it = ans.begin(); it != ans.end(); ++it) {
		if (it != ans.begin())
			printf(" ");
		printf("%d", *it);
	}
	return 0;
}