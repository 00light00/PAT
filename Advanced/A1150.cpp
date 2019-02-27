#include<bits/stdc++.h>
using namespace std;

const int MLEN = 20200;
const int MAX = 220;

int main() {
	int n, m, k;
	scanf("%d %d", &n, &m);
	vector< vector<int> >graph(n + 1, vector<int>(n + 1, MLEN));
	for (int i = 0; i < m; i++) {
		int city1, city2, len;
		scanf("%d %d %d", &city1, &city2, &len);
		graph[city1][city2] = graph[city2][city1] = len;
	}
	scanf("%d", &k);
	int minl = MLEN;
	int id = 0;
	for (int i = 1; i <= k; i++) {
		int cnt;
		scanf("%d", &cnt);
		vector<int> cycle(cnt), visit(n + 1, 0);
		for (int j = 0; j < cnt; j++)
			scanf("%d", &cycle[j]);
		int len = 0;
		int iscycle = 1, issimple = 1;
		if (cycle[0] != cycle[cnt - 1]) {
			iscycle = 0;
		}

		int cur = cycle[0], next;
		for (int j = 1; j < cnt; j++) {
			next = cycle[j];
			if (visit[next])
				issimple = 0;
			visit[next] = 1;
			len += graph[cur][next];
			cur = next;
		}
		
		for (int j = 1; j <= n; j++) {
			if (!visit[j]) {
				iscycle = 0;
				break;
			}
		}
		
		printf("Path %d:", i);
		if (len >= MLEN) {
			iscycle = 0;
			printf(" NA ");
		}
		else
			printf(" %d ", len);

		if (!iscycle)
			printf("(Not a TS cycle)\n");
		else {
			if (!issimple)
				printf("(TS cycle)\n");
			else
				printf("(TS simple cycle)\n");
			if (len < minl) {
				minl = len;
				id = i;
			}
		}
	}
	printf("Shortest Dist(%d) = %d", id, minl);
	return 0;
}