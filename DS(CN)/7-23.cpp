#include<bits/stdc++.h>
using namespace std;


int inindex[256], preindex[256];
struct node {
	char data;
	int left, right;
	int parent;
	int height;
	node(char c = '\0') :data(c), left(-1), right(-1), parent(-1), height(1) {};
};
vector<node> tree;

int insert(int root, int inl, int inr) {
	int re = root;

	int inroot = inindex[tree[root].data];
	int l = inroot - inl;
	int r = inr - inroot;
	int hl = 0, hr = 0;
	if (l > 0) {
		tree[root].left = insert(root + 1, inl, inroot - 1);
		tree[tree[root].left].parent = root;
		hl = tree[tree[root].left].height;
	}
	if (r > 0) {
		tree[root].right = insert(root + l + 1, inroot + 1, inr);
		tree[tree[root].right].parent = root;
		hr = tree[tree[root].right].height;
	}

	tree[root].height = max(hr, hl) + 1;

	return re;
}

int main() {
	int n;
	scanf("%d", &n);
	tree.resize(n);
	string pre, in;
	cin >> pre >> in;
	for (int i = 0; i < n; i++) {
		preindex[pre[i]] = i;
		inindex[in[i]] = i;
		tree[i].data = pre[i];
	}

	int root = insert(0, 0, n - 1);
	printf("%d\n", tree[0].height);
	return 0;
}