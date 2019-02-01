#include<bits/stdc++.h>
using namespace std;

const int MAX = 250001;
int main() {
	int n, m, s, d;
	scanf("%d %d %d %d", &n, &m, &s, &d);
	vector<vector<pair<int, int>>>graph(n, vector<pair<int, int>>(n, make_pair(MAX, MAX)));
	for (int i = 0; i < m; i++) {
		int c1, c2, len, cost;
		scanf("%d %d %d %d", &c1, &c2, &len, &cost);
		graph[c1][c2] = graph[c2][c1] = make_pair(len, cost);
	}
	vector<int> queue(n, 0);
	vector<int> visit(n, 0);
	int fp = 0, rp = 0;
	queue[rp++] = s;
	visit[s] = 1;
	while (fp < rp) {
		int city = queue[fp++];
		
	}
	return 0;
}