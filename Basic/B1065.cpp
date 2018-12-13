#include<bits/stdc++.h>
using namespace std;

int main() {
	map<int, int>check;
	set<int> pa;
	vector<int>re;
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int id1, id2;
		scanf("%d %d", &id1, &id2);
		check[id1] = id2;
		check[id2] = id1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int id;
		scanf("%d", &id);
		pa.insert(id);
	}
	for (set<int>::iterator it = pa.begin(); it != pa.end(); it++) {
		if (check.find(*it) == check.end()) {
			re.push_back(*it);
		}
		else {
			set<int>::iterator it_q = pa.find(check[*it]);
			if (it_q == pa.end()){
				re.push_back(*it);
			}
		}
	}
	int len = re.size();
	printf("%d\n", len);
	for (int i = 0; i < len; i++) {
		if (i > 0)
			printf(" ");
		printf("%05d", re[i]);
	}
	return 0;
}