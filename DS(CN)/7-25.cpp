#include<bits/stdc++.h>
using namespace std;

vector<int> root, stsize;

int find(int id) {
	int rt = root[id];
	while (rt != root[rt]) {
		root[rt] = root[root[rt]];
		rt = root[rt];
	}
	return rt;
}

void disjoint(int id1, int id2) {
	int root1 = find(id1), root2 = find(id2);
	if (root1 != root2) {
		if (stsize[root1] < stsize[root2]) {
			swap(root1, root2);
		}
		stsize[root1] += stsize[root2];
		root[root2] = root1;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	root.resize(n + 1), stsize.resize(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		root[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int num, ro;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			int id;
			scanf("%d", &id);
			if (j == 0) {
				ro = root[id];
			}
			else {
				disjoint(ro, id);
			}
		}
	}
	int max = 0;
	for (auto it = stsize.begin(); it != stsize.end(); it++) {
		max = max < *it ? *it : max;
	}

	printf("%d\n", max);
	return 0;
}