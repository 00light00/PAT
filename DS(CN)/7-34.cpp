#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> indegree(n + 1), re;
	graph.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		indegree[i] = k;
		for (int j = 0; j < k; j++) {
			int v2;
			scanf("%d", &v2);
			graph[v2].push_back(i);
		}

		if (k == 0) {
			re.push_back(i);
		}
	}

	int front = 0, rear = re.size();
	while (front < rear) {
		int p = re[front++];
		for (auto it = graph[p].begin(); it != graph[p].end(); it++) {
			int v = *it;
			indegree[v]--;
			if (indegree[v] == 0) {
				re.push_back(v);
				rear++;
			}
		}
	}

	if (front == n) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
	return 0;
}