#include<bits/stdc++.h>
using namespace std;

struct tnode {
	int data;
	int left, right;
	tnode(int v = 0) : data(v), left(-1), right(-1) {};
};
vector<tnode> tree;

int insert(int root, int i) {
	int re = i;
	if (root < 0)
		return re;
	int data = tree[i].data;
	if (data < tree[root].data) {
		tree[root].left = insert(tree[root].left, i);
	}
	else {
		tree[root].right = insert(tree[root].right, i);
	}
	return re = root;
}

int check(vector<int> other) {
	int re = 1;
	int n = other.size();
	vector<int> visit(n, 0);
	for (int i = 0; i < n; i++) {
		int data = other[i];
		int root = 0;
		while (root != -1) {
			if (visit[root]) {
				if (data < tree[root].data) {
					if (tree[root].left == -1)
						return re = 0;
					else {
						root = tree[root].left;
					}
				}
				else if (data > tree[root].data) {
					if (tree[root].right == -1)
						return re = 0;
					else {
						root = tree[root].right;
					}
				}
			}
			else {
				if (data == tree[root].data) {
					visit[root] = 1;
					break;
				}
				else
					return re = 0;
			}
		}
	}
	return re;
}


int main() {
	int n, l;
	scanf("%d", &n);
	while (n) {
		scanf("%d", &l);
		vector<tnode> tmp(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp[i].data);
		}
		tree = tmp;
		for (int i = 1; i < n; i++) {
			insert(0, i);
		}

		for (int i = 0; i < l; i++) {
			vector<int> othertree(n);
			for(int j = 0; j < n;j++)
				scanf("%d", &othertree[j]);
			int re = check(othertree);
			if (re) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
		scanf("%d", &n);
	}
	
	return 0;
}