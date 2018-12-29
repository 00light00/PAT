#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, flag = 0;
	scanf("%d", &n);
	for (int y = 0; y <= 100; y++) {
		for (int f = 0; f <= 100; f++) {
			if (f * 100 + y == y * 200 + f * 2 + n) {
				flag = 1;
				printf("%d.%d\n", y, f);
			}
		}
	}
	if (!flag)
		printf("No Solution\n");
	return 0;
}