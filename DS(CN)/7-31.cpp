#include<bits/stdc++.h>
using namespace std;

struct node {
	int k1, k2;
	int left, right;
	node(int v1 = 0, int v2 = 0) :k1(v1), k2(v2), left(-1), right(-1) {};
};

vector<node> tree;

int check(int i) {
	int re = 1;
	if (i == -1)
		return re;
	int left = tree[i].left, right = tree[i].right;
	int k1 = tree[i].k1, k2 = tree[i].k2;
	int l1 = k1 - 1, lmax = l1, l2 = k2 + 1, r1 = k1 + 1, rmin = r1, r2 = k2 + 1;
	if (left != -1) {
		lmax = l1 = tree[left].k1, l2 = tree[left].k2;
		int p = left;
		while (tree[p].right != -1) {
			p = tree[p].right;
			lmax = lmax < tree[p].k1 ? tree[p].k1 : lmax;
		}
	}
	if (right != -1) {
		rmin = r1 = tree[right].k1, r2 = tree[right].k2;
		int p = right;
		while (tree[p].left != -1) {
			p = tree[p].left;
			rmin = rmin > tree[p].k1 ? tree[p].k1 : rmin;
		}
	}
	if ((l1 < k1&&k1 < r1) && (lmax < k1&&k1 < rmin) && (k2 < l2&&k2 < r2)) {
		return check(left) && check(right);
	}
	else
		return re = 0;
}

int main() {
	int n;
	scanf("%d", &n);
	tree.resize(n);
	vector<int> visit(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &tree[i].k1, &tree[i].k2, &tree[i].left, &tree[i].right);
		if (tree[i].left != -1)
			visit[tree[i].left] = 1;
		if (tree[i].right != -1)
			visit[tree[i].right] = 1;
	}

	int root = -1;
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			root = i;
			break;
		}
	}

	if (check(root)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}