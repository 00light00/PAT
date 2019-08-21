#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	int sum = 0;
	int max = -1, maxl = 0, maxr = n - 1;
	int L = 0;
	for (int i = 0; i < n; i++) {
		sum += num[i];
		if (sum < 0) {
			sum = 0;
			L = i + 1;
		}
		else {
			if (max < sum) {
				max = sum;
				maxl = L;
				maxr = i;
			}
		}
	}
	if (max < 0)
		max = 0;
	printf("%d %d %d", max, num[maxl], num[maxr]);
	return 0;
}