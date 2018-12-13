#include <iostream>
using namespace std;

int prime[10010] = { 2,3,5,7 };




int main() {
	for (int i = 0;i < 10001;i++) {
		if (!prime[i]) {
			int tmp = prime[i - 1];
			while (1) {
				tmp += 2;
				int re = 1;
				for (int k = 0;k < i;k++) {
					if (tmp%prime[k] == 0) {
						re = 0;
						break;
					}
				}
				if (re) {
					prime[i] = tmp;
					break;
				}
				
			}
		}
	}

	int m, n;
	scanf("%d %d", &m, &n);
	int line = 0;
	for (int i = m;i <= n;i++) {
		line++;
		if (line > 10) {
			printf("\n");
			line = 1;
		}
		else {
			if (i > m)
				printf(" ");
		}
		printf("%d", prime[i - 1]);
	}

	return 0;
}