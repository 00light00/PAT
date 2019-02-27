#include<bits/stdc++.h>
using namespace std;

struct node {
	string val;
	int left, right;
};

string re;
vector<node> tree;

void dfs(int r) {
	if (r > 0) {
		int le = tree[r].left, ri = tree[r].right;
		if (ri > 0) {
			re.push_back('(');
			dfs(le);
		}
		re += tree[r].val;
		if (ri > 0) {
			dfs(ri);
			re.push_back(')');
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> visit(n + 1, 0);
	tree.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int l, r;
		char v[20];
		scanf("%s %d %d", v, &l, &r);
		if (l > 0)
			visit[l] = 1;
		if (r > 0)
			visit[r] = 1;
		tree[i].val = v, tree[i].left = l, tree[i].right = r;
	}

	int root = 0;
	for(int i=1;i<=n;i++)
		if (!visit[i]) {
			root = i;
			break;
		}

	dfs(root);
	if (re.size() > 1) {
		re.pop_back();
		printf("%s\n", re.c_str() + 1);
	}
	else
		printf("%s\n", re.c_str());

	return 0;
}