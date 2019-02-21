#include<bits/stdc++.h>
using namespace std;

const int MAX = 10010;
vector<int> inorder(MAX), preorder(MAX);
unordered_map<int, int> hashin;


int check(int v1, int v2, int n, int &root) {
	int re = 0;
	auto it1 = hashin.find(v1), it2 = hashin.find(v2);
	if (it1 == hashin.end() && it2 == hashin.end())
		re = -3;
	else if (it2 == hashin.end())
		re = -2;
	else if (it1 == hashin.end())
		re = -1;
	else {
		int L = 1, R = n;
		int in1 = hashin[v1], in2 = hashin[v2];

		for (int i = 1; i <= n;) {
			if (L > R)
				break;
			int root_in = hashin[preorder[i]];
			int len_left = root_in - L;
			if (in1 == root_in) {
				re = 1;
				break;
			}
			else if (in2 == root_in) {
				re = 2;
				break;
			}
			else if ((in1 < root_in && root_in < in2) || (in2 < root_in&&root_in < in1)) {
				root = inorder[root_in];
				re = 3;
				break;
			}
			else {
				if (in2 < root_in) {
					i = i + 1;
					R = root_in - 1;
				}
				else if (root_in < in1) {
					i = i + len_left + 1;
					L = root_in + 1;
				}
			}
		}
	}
	return re;
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &inorder[i]);
		hashin[inorder[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &preorder[i]);

	for (int i = 0; i < m; i++) {
		int v1, v2, root;
		scanf("%d %d", &v1, &v2);
		switch (check(v1, v2, n, root)) {
		case -1:
			printf("ERROR: %d is not found.\n", v1);
			break;
		case -2:
			printf("ERROR: %d is not found.\n", v2);
			break;
		case -3:
			printf("ERROR: %d and %d are not found.\n", v1, v2);
			break;
		case 0:
			printf("Not found\n");
			break;
		case 1:
			swap(v1, v2);
		case 2:
			printf("%d is an ancestor of %d.\n", v2, v1);
			break;
		case 3:
			printf("LCA of %d and %d is %d.\n", v1, v2, root);
			break;
		}
	}
	return 0;
}