#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > edge;

int query(vector<int> vertex) {
	int re = 1;
	for (auto it = edge.begin(); it != edge.end(); it++) {
		int v1 = it->first, v2 = it->second;
		if (!vertex[v1] && !vertex[v2]) {
			re = 0;
			break;
		}
	}
	return re;
}

int main() {
	int n, m, k;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		edge.push_back(make_pair(v1, v2));
	}

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int ns;
		vector<int> vertex(n, 0);
		scanf("%d", &ns);
		for (int j = 0; j < ns; j++) {
			int v;
			scanf("%d", &v);
			vertex[v] = 1;
		}
		if (query(vertex))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}