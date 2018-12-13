#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> re, cnt(40, 0);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		int fri = 0;
		while (num > 0) {
			fri += num % 10;
			num /= 10;
		}
		cnt[fri]++;
	}
	int cnt_fri = 0;
	for (int i = 0; i < 40; i++) {
		if (cnt[i]) {
			cnt_fri++;
			re.push_back(i);
		}
	}
	printf("%d\n", cnt_fri);
	for (int i = 0; i < cnt_fri; i++) {
		if (i > 0)
			printf(" ");
		printf("%d", re[i]);
	}
	printf("\n");
	return 0;
}