#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> link(n + 1);
	for (int i = 1; i < n; i++) {
		link[i] = i + 1;
	}
	link[n] = 1;
	int p = 1, cnt = 1;
	while (link[p] != p) {
		if (cnt == 2) {
			link[p] = link[link[p]];
			cnt = 0;
		}
		p = link[p];
		cnt++;
	}
	printf("%d\n", p);
	return 0;
}