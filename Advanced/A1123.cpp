#include <bits/stdc++.h>
using namespace std;

struct node {
	int value, height;
	node* left, right;
	node(int v = 0, int w = 1) : value(v), bs(w) {
		left = right = NULL;
	}
}
vector<int> ans;

int getheight(node* root) {

	if (root == NULL)
		return 0;
	else
		return root->height;
}

node* Lrotate(node* root) {
	node* tmp = root;
	root = root->right;
	root->right = tmp;
	return root;
}
node* Lrotate(node* root) {
	node* tmp = root;
	root = root->right;
	tmp->right = root->right;
	root->right = tmp;
	return root;
}

node* Rrotate(node* root) {
	node* tmp = root;
	root = root->left;
	tmp->left = root->left;
	root->left = tmp;
	return root;
}

node* RLrotate(node* root) {
	root->right = Rrotate(root->right);
	root = Lrotate(root);
	return root;
}

node* LRrotate(node* root) {
	root->left = Lrotate(root->left);
	root = Rrotate(root);
	return root;
}

node* balance(node* root, int l, int r) {
	if (l > r) {
		if (getheight(root->left->left) < getheight(root->left->right))
			root->left = Lrotate(root->left);
		root = Rrotate(root);
	}
	else {
		if (getheight(root->right->right) < getheight(root->right->left))
			root->right = Rrotate(root->right);
		root = Lrotate(root);
	}
	return root;
}

node* insert(node* root, int v) {
	if (root) {
		if (v < root->value) {
			root->left = insert(root->left, v);
		}
		else {
			root->right = insert(root->right, v);
		}
	}
	else {
		root = new node(v);
	}
	int hl = getheight(root->left), hr = getheight(root->right));
	if (abs(hl - hr) > 1) {
		root = balance(root, hl, hr);
	}
	root->height = max(hl, hr) + 1;
	return root;
}

int main() {
	int n;
	node* root = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int value;
		scanf("%d", &value);
		root = insert(root, value);
	}

	int re = bfs(root);

	for (int i = 0; i < n; ++i) {
		printf("%d%c", ans[i], " \n"[i == n - 1]);
	}

	if (re)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}