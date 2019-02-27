#include<bits/stdc++.h>
using namespace std;

vector<int> preorder, inorder;
unordered_map<int, int> hashin;

int LCA(int v1, int v2, int n, int &r) {
	int re = 0;
	auto it1 = hashin.find(v1), it2 = hashin.find(v2);
	if (it1 == hashin.end() && it2 == hashin.end()) {
		re = -3;
	}
	else if (it2 == hashin.end()) {
		re = -2;
	}
	else if (it1 == hashin.end()) {
		re = -1;
	}
	else {
		int in1 = hashin[v1], in2 = hashin[v2];
		int L = 1, R = n, leftlen = n - 1;
		for (int i = 1; i <= n;) {
			int root = hashin[preorder[i]];
			leftlen = root - L;
			if (root == in1) {
				re = 1;
				break;
			}
			else if (root == in2) {
				re = 2;
				break;
			}
			else if ((root - in1)*(root - in2) < 0) {
				re = 3;
				r = preorder[i];
				break;
			}
			else {
				if (root < in1&&root < in2) {
					i += leftlen + 1;
					L = root + 1;
				}
				else if (root > in1&&root > in2) {
					i++;
					R = root - 1;
				}
			}
		}
	}
	return re;
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	preorder.resize(n + 1);
	inorder.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &preorder[i]);
	}
	inorder = preorder;
	sort(inorder.begin() + 1, inorder.end());
	for(int i = 1;i<=n;i++)
		hashin[inorder[i]] = i;

	for (int i = 0; i < m; i++) {
		int v1, v2, root;
		scanf("%d %d", &v1, &v2);
		switch (LCA(v1, v2, n, root)) {
		case -3:
			printf("ERROR: %d and %d are not found.\n", v1, v2);
			break;
		case -2:
			swap(v1, v2);
		case -1:
			printf("ERROR: %d is not found.\n", v1);
			break;
		case 0:
			printf("Not found.\n");
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