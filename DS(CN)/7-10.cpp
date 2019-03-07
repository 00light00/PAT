#include<bits/stdc++.h>
using namespace std;
vector<int> root, psize;

int find(int id) {
	int r = root[id];
	while (r != root[r]) {
		root[r] = root[root[r]];
		r = root[r];
	}
	return r;
}

void unionfind(int id1, int id2) {
	int root1 = find(id1), root2 = find(id2);
	if (psize[root1] < psize[root2]) {
		swap(root1, root2);
	}
	root[root2] = root1;
	psize[root1] += psize[root2];
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	multimap<int, pair<int, int> >mp;
	root.resize(n + 1), psize.resize(n + 1, 1);
	for (int i = 0; i <= n; i++) {
		root[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int id1, id2, cost;
		scanf("%d %d %d", &id1, &id2, &cost);
		mp.insert(make_pair(cost,make_pair(id1, id2)));
	}

	int cnt = 0, sum = 0;
	for (auto it = mp.begin(); it != mp.end();it++) {
		int id1 = it->second.first, id2 = it->second.second;
		int root1 = find(id1), root2 = find(id2);
		if (root1 == root2)
			continue;
		unionfind(root1, root2);
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