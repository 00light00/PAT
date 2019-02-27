#include<bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	vector<int> preorder(n+1);
	unordered_map<int, int> hashpre;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &preorder[i]);
		hashpre[preorder[i]] = i;
	}

	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		if (!hashpre[v1] && !hashpre[v2]) {
			printf("ERROR: %d and %d are not found.\n", v1, v2);
		}
		else if (!hashpre[v1])
			printf("ERROR: %d is not found.\n", v1);
		else if (!hashpre[v2])
			printf("ERROR: %d is not found.\n", v2);
		else {
			int in1 = hashpre[v1], in2 = hashpre[v2];
			int root = in1 < in2 ? in1 : in2;
			for (int i = 1; i < root; i++) {
				if ((preorder[i] - v1)*(preorder[i] - v2) < 0) {
					root = i;
					break;
				}
			}
			if (root == in1)
				printf("%d is an ancestor of %d.\n", v1, v2);
			else if (root == in2)
				printf("%d is an ancestor of %d.\n", v2, v1);
			else {
				printf("LCA of %d and %d is %d.\n", v1, v2, preorder[root]);
			}
		}
	}
	return 0;
}