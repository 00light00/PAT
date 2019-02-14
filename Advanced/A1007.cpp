#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int max = -1, id1 = 0, id2 = n-1, p,sum = 0;
	vector<int> num;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		num.push_back(t);
		sum += t;
		if (sum < 0) {
			sum = 0;
			p = i + 1;
		}
		else if (sum > max) {
			id2 = i;
			id1 = p;
			max = sum;
		}
	}
	if (max < 0)
		max = 0;
	printf("%d %d %d\n", max, num[id1], num[id2]);
	return 0;
}