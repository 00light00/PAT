#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;

int query(int n) {
	int nv, re = 1;
	scanf("%d", &nv);
	vector<int> visit(n + 1, 0), hmt(nv);
	for (int i = 0; i < nv; i++)
		scanf("%d", &hmt[i]);

	if (nv == n + 1 && hmt[0] == hmt[nv - 1]) {
		for (int i = 0; i < nv - 1; i++) {
			int v1 = hmt[i], v2 = hmt[i + 1];
			if (!visit[v1]) {
				visit[v1] = 1;
				if (!graph[v1][v2]) {
					re = 0;
					break;
				}
			}
			else {
				re = 0;
				break;
			}
		}
	}
	else
		re = 0;
	return re;
}
int main() {
	int n, m, k;
	scanf("%d %d", &n, &m);
	graph.resize(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1][v2] = graph[v2][v1] = 1;
	}

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		if (query(n)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}