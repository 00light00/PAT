#include<bits/stdc++.h>
using namespace std;

struct node {
	int val;
	node *left, *right;
};
vector<int> ans;

node* insert(node* root, int val) {
	node * re = root;
	if (root == NULL) {
		re = new node;
		re->left = NULL;
		re->right = NULL;
		re->val = val;
	}
	else {
		int rval = root->val;
		if (val <= rval) {
			root->left = insert(root->left, val);
		}
		else if (val > rval) {
			root->right = insert(root->right, val);
		}
	}
	return re;
}

void bfs(node* root, int n) {
	vector<node*> que(n);
	int front = -1, rear = -1;
	if (root != NULL) {
		que[++rear] = root;
		ans.push_back(rear - front);
		front = rear;
	}
	for (int i = 0; i < n; i++) {
		node *p = que[i];
		if (p->left != NULL) {
			que[++rear] = p->left;
		}
		if (p->right != NULL) {
			que[++rear] = p->right;
		}
		if (i == front) {
			ans.push_back(rear - front);
			front = rear;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		root = insert(root, num);
	}

	bfs(root, n);
	int a = 0, b = 0;
	int len = ans.size();
	if (len > 1)
		a = ans[len - 2];
	if (len > 2)
		b = ans[len - 3];
	printf("%d + %d = %d\n", a, b, a + b);
	return 0;
}