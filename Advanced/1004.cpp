#include<bits/stdc++.h>
using namespace std;

struct node {
	vector<int> child;
	int num;
};
const int MAX = 110;
vector<node> tree(MAX);

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int pid, cnum;
		scanf("%d %d", &pid, &cnum);
		tree[pid].num = cnum;
		for (int j = 0; j < cnum; j++) {
			int child;
			scanf("%d", &child);
			tree[pid].child.push_back(child);
		}
	}

	vector<int> q1, q2;
	q1.push_back(01);
	int flag = 0;
	while (!q1.empty() || !q2.empty()) {
		int cnt = 0;
		for (auto it = q1.begin(); it != q1.end(); it++) {
			int pid = *it;
			if (tree[pid].num) {
				for (int i = 0; i < tree[pid].num; i++) {
					q2.push_back(tree[pid].child[i]);
				}
			}
			else
				cnt++;
		}
		if (flag)
			printf(" ");
		else
			flag = 1;
		printf("%d", cnt);
		q1 = q2;
		q2.clear();
	}
	return 0;
}