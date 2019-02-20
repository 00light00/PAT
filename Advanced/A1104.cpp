#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<double> num(n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &num[i]);
	}

	double total = 0;
	for (int i = 0; i < n; i++) {
		total += num[i] * (n - i)*(i + 1);
	}
	printf("%.2f\n", total);
	return 0;
}