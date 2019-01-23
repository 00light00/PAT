#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, cnt = 1, flag = 0;
	scanf("%d", &n);
	int n_t = n;
	while (n_t > 9) {
		cnt *= 10;
		n_t /= 10;
	}
	n_t = n;
	while (cnt > 0) {
		int num = n_t / cnt;
		if (num||cnt==10000) {
			if (flag&&num) {
				printf("a");
				flag = 0;
			}
			if(num)
				printf("%c", 'a' + num);
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
		}
		else {
			flag++;
		}
		n_t %= cnt;
		cnt /= 10;
	}
	if (n == 0)
		printf("a");
	return 0;
}