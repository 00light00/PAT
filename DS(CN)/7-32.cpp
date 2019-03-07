#include<bits/stdc++.h>
using namespace std;

vector<int> root, rk;

int find(int v) {
	while (v != root[v]) {
		root[v] = root[root[v]];
		v = root[v];
	}
	return v;
}

void disjoint(int v1, int v2) {
	int r1 = find(v1), r2 = find(v2);
	if (r1 != r2) {
		if (rk[r1] < rk[r2]) 
			swap(r1, r2);
		root[r2] = r1;
		rk[r1] += rk[r2];
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> degree(n + 1);
	root.resize(n + 1), rk.resize(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		root[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		degree[v1]++;
		degree[v2]++;
		disjoint(v1, v2);
	}

	int re = 1;
	int rt = find(1);
	for (int i = 1; i <= n; i++) {
		if (find(i) != rt) {
			re = 0;
			break;
		}
		if (degree[i] % 2) {
			re = 0;
			break;
		}
	}


	printf("%d\n", re);
	return 0;
}