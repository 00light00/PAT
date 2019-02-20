#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	map<int, int> num;
	for (int i = 0; i < n; i++) {
		int m;
		scanf("%d", &m);
		num[m]++;
	}
	for (int i = 1; i < 100011; i++)
		if (!num[i]) {
			printf("%d\n", i);
			break;
		}
	return 0;
}