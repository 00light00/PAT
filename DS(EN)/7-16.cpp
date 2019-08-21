#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	scanf("%d", &n);
	vector<int> num(n), mun(n), visit(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		mun[num[i]] = i;
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			if (num[i] == i) {
				cnt1++;
			}
			else {
				cnt2++;
				int p = num[i], next=num[num[i]];
				while (p != i) {
					visit[p] = 1;
					p = next;
					next = num[next];
				}
			}
		}
	}
	int re = n - cnt1 + cnt2 - 2;
	if (num[0] == 0)
		re += 2;
	printf("%d\n", re);
	return 0;
}