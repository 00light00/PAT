#include<bits/stdc++.h>
using namespace std;

struct node {
	int l, r;
};
vector<node> tree;
vector<int> complete;

int judge(int root, int pos) {
	int re = 1;
	if (pos < complete.size()) {
		complete[pos] = root;
		int l = tree[root].l, r = tree[root].r;
		int rel = 1, rer = 1;
		if (l >= 0) {
			rel = judge(l, pos * 2 + 1);
		}
		if (r >= 0) {
			rer = judge(r, pos * 2 + 2);
		}
		if (rel&&rer)
			return re;
		else {
			re = 0;
			return re;
		}
	}
	else {
		re = 0;
		return re;
	}
}

int main() {
	int n, root = -1;
	scanf("%d", &n);
	tree.resize(n), complete.resize(n, -1);
	vector<int> visit(n, 0);
	for (int i = 0; i < n; i++) {
		char lc[5], rc[5];
		scanf("%s %s", lc, rc);
		if (lc[0] != '-') {
			int pos = stoi(lc);
			tree[i].l = pos;
			visit[pos] = 1;
		}
		else
			tree[i].l = -1;
		if (rc[0] != '-') {
			int pos = stoi(rc);
			tree[i].r = pos;
			visit[pos] = 1;
		}
		else
			tree[i].r = -1;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i])
			root = i;
	}

	if (judge(root, 0)) {
		printf("YES %d\n", complete[n - 1]);
	}
	else
		printf("NO %d\n", root);
	return 0;
}