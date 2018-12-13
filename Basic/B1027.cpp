#include <iostream>
#include <cmath>
using namespace std;

int main() {
	char size;
	int n;
	scanf("%d %c", &n, &size);
	int cnt = 0;
	for (; 2 * cnt*cnt - 1 <= n; cnt++);
	cnt--;
	
	int re = n - 2 * cnt*cnt + 1;
	for (int i = 0; i < 2 * cnt-1; i++) {
		int tmp = abs(i + 1 - cnt);
		for (int j = 0; j < cnt - tmp - 1; j++) {
			printf(" ");
		}
		for (int j = 0; j < 2 * tmp + 1; j++) {
			printf("%c", size);
		}
		printf("\n");
	}
	printf("%d\n", re);
	return 0;
}