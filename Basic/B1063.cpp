#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int rad = a * a + b * b;
		max = max < rad ? rad : max;
	}
	printf("%.2f\n", sqrt(max));

	return 0;
}