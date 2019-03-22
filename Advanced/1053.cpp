//要求到叶结点的weight，中间的不行。。。

#include<bits/stdc++.h>
using namespace std;

struct node {
	int weight;
	vector<int> child;
};
const int MAX = 110;
vector<node> tree(MAX);
vector<int> re;

bool comp(int a, int b) {
	return tree[a].weight > tree[b].weight;
}

void print() {
	for (auto it = re.begin(); it != re.end(); it++) {
		if (it != re.begin())
			printf(" ");
		printf("%d", *it);
	}
	printf("\n");
}

void dfs(int i, int s) {
	int w = tree[i].weight;
	s -= w;
	re.push_back(w);
	if (s == 0 && tree[i].child.empty()) {
		print();

	}
	else if (s > 0) {
		for (auto it = tree[i].child.begin(); it != tree[i].child.end(); it++) {
			dfs(*it, s);
		}
	}
	s += tree[i].weight;
	re.pop_back();
	return;
}

int main() {
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tree[i].weight);
	}

	for (int i = 0; i < m; i++) {
		int id, cnum;
		scanf("%d %d", &id, &cnum);
		for (int j = 0; j < cnum; j++) {
			int cid;
			scanf("%d", &cid);
			tree[id].child.push_back(cid);
		}
		sort(tree[id].child.begin(), tree[id].child.end(), comp);
	}

	
	dfs(0, s);
	return 0;
}