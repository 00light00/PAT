#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	vector<int> num;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int nu;
		scanf("%d", &nu);
		num.push_back(nu);
	}

	sort(num.begin(), num.end());
	int len = num.size();
	double sum = num[0];
	for (int i = 1; i < len; i++) {
		sum += num[i];
		sum /= 2;
	}
	printf("%d\n", (int)sum);
	return 0;
}