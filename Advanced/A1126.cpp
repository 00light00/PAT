#include<bits/stdc++.h>
using namespace std;

const int MAX = 555;
int root[MAX], rk[MAX];

int find(int v) {
	int re;
	if (root[v]) {
		re = root[v];
		while (root[re] != 0) {
			root[v] = root[re];
			re = root[re];
		}
	}
	else
		re = v;
	return re;
}

void joint(int v1, int v2) {
	if (rk[v1] < rk[v2])
		swap(v1, v2);
	rk[v1]++;
	root[v2] = v1;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> degreev(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int v1, v2, r1, r2;
		scanf("%d %d", &v1, &v2);
		degreev[v1]++;
		degreev[v2]++;
		r1 = find(v1);
		r2 = find(v2);
		if (r1 != r2)
			joint(r1, r2);
	}

	int cntodd = 0, disjoint = 1, rt=find(1);
	for (int i = 1; i <= n; i++) {
		if (i > 1)
			printf(" ");
		printf("%d", degreev[i]);
		if (degreev[i] % 2)
			cntodd++;
		if (rt != find(i))
			disjoint = 0;
	}
	printf("\n");

	if (disjoint&&cntodd == 0) {
		printf("Eulerian\n");
	}
	else if (disjoint&&cntodd == 2) {
		printf("Semi-Eulerian\n");
	}
	else
		printf("Non-Eulerian\n");
	return 0;
}