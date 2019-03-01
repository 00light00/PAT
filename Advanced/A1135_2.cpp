#include<bits/stdc++.h>
using namespace std;

struct node {
	int val;
	node* left, *right;
	int isred;
};

node* insert(node * root, int v) {
	node * re = NULL;
	int val = abs(v);
	if (root == NULL) {
		re = new node;
		re->left = NULL;
		re->right = NULL;
		if (v < 0) {
			re->isred = 1;
		}
		else
			re->isred = 0;
		re->val = val;
	}
	else {
		int val_r = root->val;
		re = root;
		if (val < val_r)
			root->left = insert(root->left, v);
		else if (val_r < val)
			root->right = insert(root->right, v);
	}
	return re;
}

int dfs4(node* root) {
	int re = 1;
	if (root) {
		if (root->isred) {
			if((root->right&&root->right->isred)||(root->left&&root->left->isred))
				re = 0;
		}
		if (re) {
			re = dfs4(root->left) && dfs4(root->right);
		}
	}
	return re;
}

int dfs5(node* root,int &flag) {
	int re = 1;
	if (root) {
		int rel = dfs5(root->left,flag);
		int rer = dfs5(root->right,flag);
		if (flag) {
			if (rel != rer) {
				flag = 0;
			}
		}
		if (root->isred)
			re = rel;
		else
			re += rel;
	}
	return re;
}

int isbrtree(node* root) {
	int re2 = 1, re4 = 1, re5 = 1;
	if (root->isred)
		re2 = 0;
	re4 = dfs4(root);
	int cnt = dfs5(root, re5);
	return re2 && re4 && re5;
}

int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int n;
		scanf("%d", &n);
		node *root = NULL;
		for (int j = 0; j < n; j++) {
			int t;
			scanf("%d", &t);
			root = insert(root, t);
		}

		if (isbrtree(root))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}