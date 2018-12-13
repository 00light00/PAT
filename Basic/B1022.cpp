#include <iostream>
using namespace std;

const int MAX = 66;
int radix[MAX];

int main() {
	long long a, b;
	int d;
	scanf("%lld %lld %d", &a, &b, &d);
	long long sum = a + b;
	int cnt = 0;
	for (cnt = 0; sum > 0; cnt++) {
		radix[cnt] = sum % d;
		sum /= d;
	}
	if (cnt == 0)
		cnt++;
	for (int i = cnt - 1; i >= 0; i--) {
		printf("%d", radix[i]);
	}
	printf("\n");

	return 0;
}