#include<bits/stdc++.h>
using namespace std;

typedef int Tree;
struct Tnode {
	int data;
	Tree l, r;
	int flag;
};

bool check(vector<Tnode> tree, int n) {
	bool re = false;
	vector<int> binTree;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d",&num);
		binTree.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		int nodeCheck = binTree[i];
		for (int j = 0; j >= 0;) {
			if (tree[j].flag) {
				if (tree[j].data < nodeCheck)
					j = tree[j].r;
				else if (tree[j].data > nodeCheck)
					j = tree[j].l;
				else
					return re;
			}
			else {
				if (tree[j].data == nodeCheck) {
					tree[j].flag = 1;
					break;
				}
				else
					return re;
			}
		}
	}
	return re = true;
}


int main() {
	int n, l;
	scanf("%d", &n);
	vector<Tnode> tree(n);
	while (n) {
		scanf("%d", &l);
		for (int i = 0; i < n; i++) {
			int data;
			scanf("%d", &data);
			tree[i].data = data;
			tree[i].l = tree[i].r = -1;
			tree[i].flag = 0;

			for (int j = 0; j >= 0;) {
				if (data > tree[j].data) {
					if (tree[j].r > 0)
						j = tree[j].r;
					else {
						tree[j].r = i;
						break;
					}
				}
				else {
					if (tree[j].l > 0)
						j = tree[j].l;
					else {
						tree[j].l = i;
						break;
					}
				}
			}
		}

		for (int i = 0; i < l; i++) {
			if (check(tree, n))
				printf("Yes\n");
			else
				printf("No\n");
		}

		scanf("%d", &n);
	}
	return 0;
}