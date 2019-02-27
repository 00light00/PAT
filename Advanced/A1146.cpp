#include<bits/stdc++.h>
using namespace std;

const int MAX = 1010;
vector<int> graph[MAX];

int main() {
	int n, m, k;
	scanf("%d %d", &n, &m);
	vector<int>degree(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int vs, ve;
		scanf("%d %d", &vs, &ve);
		graph[vs].push_back(ve);
		degree[ve]++;
	}

	scanf("%d", &k);
	vector<int> re;
	for (int i = 0; i < k; i++) {
		vector<int> topological(n), degree2(degree);
		for (int j = 0; j < n; j++) {
			scanf("%d", &topological[j]);
		}

		int isnot = 0;
		for (int j = 0; j < n; j++) {
			int v = topological[j];
			if (degree2[v] > 0) {
				isnot = 1;
				break;
			}
			for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
				degree2[*it]--;
			}
		}

		if (isnot)
			re.push_back(i);
	}

	for (auto it = re.begin(); it != re.end(); it++) {
		if (it != re.begin())
			printf(" ");
		printf("%d", *it);
	}
	return 0;
}