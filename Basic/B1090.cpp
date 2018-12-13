#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	multimap<int, int>check;
	for (int i = 0; i < n; i++) {
		int id1, id2;
		scanf("%d %d", &id1, &id2);
		check.insert(make_pair(id1,id2));
		check.insert(make_pair(id2,id1));
	}

	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		vector<int>list;
		map<int, int>checklist;
		for (int j = 0; j < num; j++) {
			int id;
			scanf("%d", &id);
			list.push_back(id);
			auto check_re = check.equal_range(id);
			for (auto re = check_re.first; re != check_re.second; re++) {
				checklist[re->second]++;
			}
		}
		int flag = 1;
		for(int j=0;j<num;j++)
			if (checklist[list[j]]) {
				flag = 0;
				break;
			}
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}