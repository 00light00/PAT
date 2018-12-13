#include <iostream>
using namespace std;

const int MAX = 100010;
double num[MAX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &num[i]);
	}

	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += num[i] * (i + 1)*(n - i);
	}
	printf("%.2f\n", sum);
	return 0;
}