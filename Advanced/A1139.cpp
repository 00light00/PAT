#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
unordered_map<int,vector<int>> graph1;
unordered_map<int,map<int,int> > graph2;
int main() {
	int n, m, k;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		char id1[10], id2[10];
		scanf("%s %s", id1, id2);
		int len1 = strlen(id1), len2 = strlen(id2);
		int i1, i2;
		if (len1 > 4)
			i1 = stoi(id1 + 1);
		else
			i1 = stoi(id1);
		if (len2 > 4)
			i2 = stoi(id2 + 1);
		else
			i2 = stoi(id2);
		if (len1==len2) {
			graph1[i1].push_back(i2);
			graph1[i2].push_back(i1);
		}
		graph2[i1][i2] = graph2[i2][i1] = 1;
	}

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		vector<pii> re;
		v1 = abs(v1), v2 = abs(v2);
		for (auto it1 = graph1[v1].begin(); it1 != graph1[v1].end(); it1++) {
			for (auto it2 = graph1[v2].begin(); it2 != graph1[v2].end(); it2++) {
				if (*it1 != v2 & *it2 != v1) {
					if (graph2[*it1][*it2]) {
						re.push_back(make_pair(*it1, *it2));
					}
				}
			}
		}

		sort(re.begin(), re.end());
		printf("%d\n", re.size());
		if(!re.empty())
			for (auto it = re.begin(); it != re.end(); it++) {
				printf("%04d %04d\n", it->first, it->second);
			}
	}
	return 0;
}