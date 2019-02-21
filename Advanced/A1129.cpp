#include<bits/stdc++.h>
using namespace std;

struct rec {
	int cnt, index;
	rec(int i = 0, int c = 0) :cnt(c), index(i) {};
	bool operator< (rec op)const {
		return cnt != op.cnt ? cnt > op.cnt:index < op.index;
	}
};

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	set<rec> re;
	map<int, int> query;
	for (int i = 0; i < n; i++) {
		int q;
		scanf("%d", &q);
		int cnt = 0;
		if (!re.empty()) {
			printf("%d:", q);
			for (auto it = re.begin(); it != re.end() && cnt < k; it++, cnt++) {
				printf(" %d", it->index);
			}
			printf("\n");
		}
		auto it = re.find(rec(q, query[q]));
		if (it != re.end())
			re.erase(it);
		re.insert(rec(q, ++query[q]));
	}
	return 0;
}