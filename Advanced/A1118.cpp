#include<bits/stdc++.h>
using namespace std;

const int MAX = 10010;
int tree[MAX], height[MAX];

int find(int b) {
	int root = b;
	if (tree[root]) {
		root = tree[b];
		while (tree[root] != 0) {
			tree[b] = tree[root];
			root = tree[root];
		}
	}
	return root;
}

void joint(int b1, int b2) {
	int tree1 = find(b1);
	int tree2 = find(b2);
	if (height[tree1] > height[tree2])
		swap(tree1, tree2);
	tree[tree1] = tree2;
	height[tree2]++;
}

int main() {
	int n;
	scanf("%d", &n);
	set<int> tree;
	int cntb = 0;
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		vector<int> treebirds(k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &treebirds[j]);
			if (j > 0)
				joint(treebirds[j], treebirds[j - 1]);
			cntb = cntb < treebirds[j] ? treebirds[j] : cntb;
		}
	}
	set<int> cntt;
	for (int i = 1; i <= cntb; i++) {
		cntt.insert(find(i));
	}
	printf("%d %d\n", cntt.size(), cntb);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int b1, b2;
		scanf("%d %d", &b1, &b2);
		int t1 = find(b1);
		int t2 = find(b2);
		if (t1 != t2)
			printf("No\n");
		else
			printf("Yes\n");
	}

	return 0;
}