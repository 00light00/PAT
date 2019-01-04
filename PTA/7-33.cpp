#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	int a1, a2, b1, b2, re1, re2;
	scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
	re1 = a1 * b2 + a2 * b1;
	re2 = b1 * b2;
	int g = gcd(re1, re2);
	re1 /= g;
	re2 /= g;
	printf("%d", re1);
	if (re2 != 1)
		printf("/%d", re2);

	return 0;
}