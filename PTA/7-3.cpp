#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, re = 0;
	scanf("%d", &n);
	while (n > 0) {
		re *= 10;
		re += n % 10;
		n /= 10;
	}
	printf("%d\n", re);
	return 0;
}