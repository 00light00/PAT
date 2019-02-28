#include<bits/stdc++.h>
using namespace std;

struct node {
	int id, val, next;
};

int main() {
	int st, n, k;
	scanf("%d %d %d", &st, &n, &k);
	vector<node> all, linklist, ans1, ans2, ans3;
	map<int, int> index;
	for (int i = 0; i < n; i++) {
		node nod;
		scanf("%d %d %d", &nod.id, &nod.val, &nod.next);
		all.push_back(nod);
		index[nod.id] = i;
	}

	int p = st;
	while (p != -1) {
		linklist.push_back(all[index[p]]);
		p = all[index[p]].next;
	}

	for (auto it = linklist.begin(); it != linklist.end(); it++) {
		int val = it->val;
		if (val < 0) {
			ans1.push_back(*it);
		}
		else if (val <= k) {
			ans2.push_back(*it);
		}
		else {
			ans3.push_back(*it);
		}
	}

	int flag = 0;
	for (auto it = ans1.begin(); it != ans1.end(); it++) {
		int id = it->id, val = it->val;
		if (flag) {
			printf(" %05d\n", id);
		}
		else {
			flag = 1;
		}
		printf("%05d %d", id, val);
	}	
	for (auto it = ans2.begin(); it != ans2.end(); it++) {
		int id = it->id, val = it->val;
		if (flag) {
			printf(" %05d\n", id);
		}
		else {
			flag = 1;
		}
		printf("%05d %d", id, val);
	}	
	for (auto it = ans3.begin(); it != ans3.end(); it++) {
		int id = it->id, val = it->val;
		if (flag) {
			printf(" %05d\n", id);
		}
		else {
			flag = 1;
		}
		printf("%05d %d", id, val);
	}
	printf(" -1");

	return 0;
}