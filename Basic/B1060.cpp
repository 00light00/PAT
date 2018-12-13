#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int>mile;
	for (int i = 0; i < n; i++) {
		int m;
		scanf("%d", &m);
		mile.push_back(m);
	}

	sort(mile.begin(), mile.end(),greater<int>());
	if (mile[n - 1] >= n) {
		printf("%d\n", n);
	}
	else {
		for (int i = 0; i < n; i++) {
			if (mile[i] <= i + 1) {
				printf("%d\n", i);
				break;
			}
		}
	}
	
	return 0;
}