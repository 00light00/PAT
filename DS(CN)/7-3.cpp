#include<bits/stdc++.h>
using namespace std;

#define NULL -1

struct node {
	char data;
	int lnode, rnode;
	node(char a, int b, int c) :data(a), lnode(b), rnode(c) {};
};
vector<node> A, B;

bool check(int a, int b) {
	bool re = false;
	if (a == NULL && b == NULL)
		re = true;
	else if ((a == NULL && b != NULL) || (a != NULL && b== NULL)) {
		re = false;
	}
	else if (A[a].data!=B[b].data) {
		re = false;
	}
	else {
		re = (check(A[a].lnode, B[b].lnode) && check(A[a].rnode, B[b].rnode)) ||
			(check(A[a].lnode, B[b].rnode) && check(A[a].rnode, B[b].lnode));
	}
	return re;
}

int main() {
	int n1,n2;
	int root1 = NULL, root2 = NULL;
	scanf("%d\n", &n1);
	vector<int> root(n1, 0);
	for (int i = 0; i < n1; i++) {
		char d, cl, cr;
		int l, r;
		scanf("%c %c %c\n", &d, &cl, &cr);
		if (cl != '-') {
			l = cl - '0';
			root[l]++;
		}
		else
			l = NULL;
		if (cr != '-') {
			r = cr - '0';
			root[r]++;
		}
		else
			r = NULL;
		A.push_back(node(d, l, r));
	}
	for (int i = 0; i < n1; i++) {
		if (root[i] == 0)
			root1 = i;
		else
			root[i] = 0;
	}

	scanf("%d\n", &n2);
	for (int i = 0; i < n2; i++) {
		char d, cl, cr;
		int l, r;
		scanf("%c %c %c\n", &d, &cl, &cr);
		if (cl != '-') {
			l = cl - '0';
			root[l]++;
		}
		else
			l = NULL;
		if (cr != '-') {
			r = cr - '0';
			root[r]++;
		}
		else
			r = NULL;
		B.push_back(node(d, l, r));
		
	}
	for (int i = 0; i < n1; i++) {
		if (root[i] == 0)
			root2 = i;
	}

	bool re;
	if (n1 != n2)
		re = false;
	else
		re = check(root1, root2);
	if (re)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}