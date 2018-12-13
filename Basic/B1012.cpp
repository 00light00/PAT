#include <iostream>
using namespace std;

int main() {
	long long A, B, sum, digit = 1;
	int D;
	scanf("%lld %lld %d", &A, &B, &D);
	sum = A + B;
	while (D*digit < sum) {
		digit *= D;
	}
	while (digit > 0) {
		printf("%d", sum / digit);
		sum = sum % digit;
		digit /= D;
	}
	printf("\n");
	return 0;
}