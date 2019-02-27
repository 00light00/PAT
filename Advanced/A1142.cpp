#include<bits/stdc++.h>
using namespace std;

int main() {
	int nv, ne, m;
	scanf("%d %d", &nv, &ne);
	vector<vector<int> > graph(nv + 1, vector<int>(nv + 1));
	for (int i = 0; i < ne; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1][v2] = graph[v2][v1] = 1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int k, isClique = 1, isMaximal = 1;
		scanf("%d", &k);
		vector<int> query(k), visit(nv + 1);
		for (int j = 0; j < k; j++) {
			scanf("%d", &query[j]);
			visit[query[j]] = 1;
		}
		for (int j = 0; j < k; j++) {
			int v1 = query[j];
			for (int l = 0; l < j; l++) {
				int v2 = query[l];
				if (!graph[v1][v2]) {
					isClique = 0;
					break;
				}
			}
			if (!isClique)
				break;
		}
		if (isClique) {
			for (int j = 1; j <= nv; j++) {
				if (!visit[j]) {
					int addmore = 1;
					for (int l = 0; l < k; l++) {
						if (!graph[j][query[l]]) {
							addmore = 0;
							break;
						}
					}
					if (addmore) {
						isMaximal = 0;
						break;
					}
				}
			}
			if (isMaximal)
				printf("Yes\n");
			else
				printf("Not Maximal\n");
		}
		else
			printf("Not a Clique\n");
	}
	return 0;
}