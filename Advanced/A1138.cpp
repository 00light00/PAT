//use hash to accelrate finding the index of inorder. 
//But the number of node is out of range(1,N). 
//We can use vector as the simple version.
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> preorder(n + 1), inorder(n + 1);
	map <int, int> hashin;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &preorder[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &inorder[i]);
		hashin[inorder[i]] = i;
	}

	int L = 1, R = n;
	for (int i = 1; i <= n; i++) {
		int root = hashin[preorder[i]];
		if (L == R) {
			printf("%d\n", preorder[i]);
			break;
		}
		else if (root > L)
			R = root - 1;
		else if (root==L)
			L = root + 1;
	}

	return 0;
}