#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	map<int, int> check;
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		check[num]++;
	}
	int st_num = 0, it_num = 0;
	for (int i = 0; i < n; i++) {
		string name;
		int cnt, num;
		cin >> name >> cnt;
		vector<int> re;
		for (int i = 0; i < cnt; i++) {
			scanf("%d", &num);
			if (check[num])
				re.push_back(num);
		}
		int len = re.size();
		if (len) {
			st_num++;
			it_num += len;
			printf("%s:", name.c_str());
			for (int j = 0; j < len; j++) {
				printf(" %04d", re[j]);
			}
			printf("\n");
		}
	}
	printf("%d %d\n", st_num, it_num);
	return 0;
}