#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, cnt = 1;
	scanf("%d", &n);
	int n_t = n;
	while (n_t > 9) {
		cnt *= 10;
		n_t /= 10;
	}
	while (cnt > 0) {
		printf("%c", 'a' + n / cnt);
		switch (cnt) {
		case 10:
		case 100000:
			printf("S");
			break;
		case 100:
		case 1000000:
			printf("B");
			break;
		case 1000:
		case 10000000:
			printf("Q");
			break;
		case 10000:
			printf("W");
			break;
		case 100000000:
			printf("Y");
			break;
		}
		n %= cnt;
		cnt /= 10;
	}
	return 0;
}