#include<bits/stdc++.h>
using namespace std;

const int MAX = 30;
struct node {
	int val;
	int lc, rc;
}tree[MAX];
int visit[MAX];
vector<int> leans, inans;

void leorder(int root, int n) {
	leans.push_back(root);
	for (int i = 0; i < n; i++) {
		int p = leans[i];
		if(tree[p].rc!=-1)
			leans.push_back(tree[p].rc);
		if(tree[p].lc!=-1)
			leans.push_back(tree[p].lc);
	}
}


void inorder(int root) {
	if (root == -1)
		return;
	else {
		inorder(tree[root].rc);
		inans.push_back(root);
		inorder(tree[root].lc);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char l[2], r[2];
		scanf("%s %s", l, r);
		if (l[0] != '-') {
			int pos = l[0] - '0';
			tree[i].lc = pos;
			visit[pos] = 1;
		}
		else
			tree[i].lc = -1;
		if (r[0] != '-') {
			int pos = r[0] - '0';
			tree[i].rc = pos;
			visit[pos] = 1;
		}
		else
			tree[i].rc = -1;
	}
	int root = -1;
	for (int i = 0; i < n; i++) {
		if (!visit[i])
			root = i;
	}

	leorder(root, n);
	inorder(root);

	for (int i = 0; i < n; i++) {
		if (i > 0)
			printf(" ");
		printf("%d", leans[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		if (i > 0)
			printf(" ");
		printf("%d", inans[i]);
	}
	printf("\n");
	return 0;
}