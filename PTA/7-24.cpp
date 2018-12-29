#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	int u, d;
	scanf("%d/%d", &u, &d);
	int g = gcd(u, d);
	printf("%d/%d\n", u / g, d / g);
	return 0;
}