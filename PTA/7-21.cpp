#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, flag = 0;
	scanf("%d", &n);
	for (int x = 1; x*x <= n; x++) {
		for (int y = x; y*y <= n; y++) {
			if (x*x + y * y == n) {
				flag = 1;
				printf("%d %d\n", x, y);
			}
		}
	}
	if (!flag)
		printf("No Solution\n");
	return 0;
}