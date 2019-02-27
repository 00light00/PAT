#include<bits/stdc++.h>
using namespace std;

vector<int> tree_in, tree_pre;
map<int, int> hashin;

int getcnt(int proot,int l,int r)

int judge(int proot, int l, int r) {
	int re = 0;
	int root = hashin[abs(tree_pre[proot])];
	int isred = tree_pre[proot] < 0 ? 1 : 0;
	int lenl = root - l, lenr = r - root;
	int l = getcnt(proot + 1, l, root - 1);
	int r = getcnt(proot + lenl + 1, root + 1, r);
	if (l != r)
		return re;
	if (lenl&&lenr&&tree_pre[proot + 1] < 0 && tree_pre[pree + lenl + 1] < 0)
		return re;
	else {
		return re = judge(proot + 1, l, root - 1) && judge(proot + lenl + 1, root + 1, r);
	}
}


int red_black(int n) {
	int re = 0;
	if (tree_pre[0] < 0) {
		return re;
	}

	re = judge(0, 0, n - 1);
	return re;
}

int main() {
	int k, n;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		tree_in.resize(n), tree_pre.resize(n);
		for (int j = 0; j < n; j++) {
			scanf("%d", tree_pre[j]);
			tree_in[j] = abs(tree_pre[j]);
			hashin[tree_in[j]] = j;
		}
		sort(tree_in.begin(), tree_in.end());
		if (red_black(n))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}