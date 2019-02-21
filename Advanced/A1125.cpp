#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> rope(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &rope[i]);
	}

	sort(rope.begin(), rope.end());

	int len = rope[0];
	for (int i = 1; i < n; i++) {
		len += rope[i];
		len /= 2;
	}

	printf("%d\n", len);
	return 0;
}