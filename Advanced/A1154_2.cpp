#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > edge;

int kcolor(int n) {
	int re = 0;
	unordered_set<int > color_set;
	vector<int> color;
	for (int i = 0; i < n; i++) {
		int co;
		scanf("%d", &co);
		color_set.insert(co);
		color.push_back(co);
	}
	for (auto it = edge.begin(); it != edge.end(); it++) {
		int v1 = it->first, v2 = it->second;
		if (color[v1] == color[v2]) {
			return re;
		}
	}

	re = color_set.size();
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
		int cnt = 0;
		cnt = kcolor(n);
		if (cnt)
			printf("%d-coloring\n", cnt);
		else
			printf("No\n");
	}
	return 0;
}