#include<bits/stdc++.h>
using namespace std;

int find(vector<int> & root, int id) {
	int r = root[id];
	while (r > 0) {
		if (root[r] > 0) {
			root[id] = root[r];
		}
		r = root[id];
	}
	return r;
}

void unionfind(vector<int> & root, int root1, int root2) {
	if (root[root1] < root[root2]) {
		swap(root1, root2);
	}
	root[root1] = root2;
	root[root2]--;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> root(n + 1, -1);
	multimap<int, pair<int, int> >mp;
	for (int i = 0; i < m; i++) {
		int id1, id2, cost;
		scanf("%d %d %d", &id1, &id2, &cost);
		mp.insert(make_pair(cost,make_pair(id1, id2)));
	}

	int cnt = 0, sum = 0;
	for (auto it = mp.begin(); it != mp.end();it++) {
		int id1 = it->second.first, id2 = it->second.second;
		int root1 = find(root, id1), root2 = find(root, id2);
		if (root1 == root2)
			continue;
		unionfind(root, root1, root2);
		cnt++;
		sum += it->first;
		if (cnt == n - 1)
			break;
	}
	if (cnt < n - 1)
		sum = -1;
	printf("%d\n", sum);
	return 0;
}