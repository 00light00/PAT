#include<bits/stdc++.h>
using namespace std;

vector <int> tree, re;

void postorder(int i, int n) {
	if (i > n) {
		return;
	}
	else {
		postorder(2 * i, n);
		postorder(2 * i + 1, n);
		re.push_back(tree[i]);
	}
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) {
		tree.resize(n + 1);
		re.clear();
		for (int j = 1; j <= n; j++)
			scanf("%d", &tree[j]);
		
		int ismax = 1, ismin = 1;
		for (int j = 2; j <= n; j++) {
			if (tree[j] < tree[j / 2])
				ismin = 0;
			if (tree[j / 2] < tree[j])
				ismax = 0;
		}

		if (ismax)
			printf("Max");
		else if (ismin)
			printf("Min");
		else
			printf("Not");
		printf(" Heap\n");

		postorder(1,n);

		for (auto it = re.begin(); it != re.end(); it++) {
			if (it != re.begin())
				printf(" ");
			printf("%d", *it);
		}
		printf("\n");
	}
	return 0;
}