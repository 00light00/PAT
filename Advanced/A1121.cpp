#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	unordered_map<int, int> notSingle, isshow;
	set<int> re;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int s1, s2;
		scanf("%d %d", &s1, &s2);
		notSingle[s1] = s2;
		notSingle[s2] = s1;
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int man;
		scanf("%d", &man);
		if (notSingle.find(man) == notSingle.end())
			re.insert(man);
		else {
			int cp = notSingle[man];
			if (isshow[cp]) {
				re.erase(cp);
			}
			else {
				re.insert(man);
				isshow[man] = 1;
			}
		}
	}

	printf("%d\n", re.size());
	for (auto it = re.begin(); it != re.end(); it++) {
		if (it != re.begin())
			printf(" ");
		printf("%05d", *it);
	}
	return 0;
}