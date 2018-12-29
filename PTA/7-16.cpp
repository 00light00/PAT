#include<bits/stdc++.h>
using namespace std;

int main() {
	int a;
	scanf("%d", &a);
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int l = 0; l < 4; l++) {
				if (i != j && j != l && l != i) {
					if (cnt > 0) {
						if (cnt % 6 == 0)
							printf("\n");
						else
							printf(" ");
					}
					printf("%d%d%d", a + i, a + j, a + l);
					cnt++;
				}
			}
		}
	}
	return 0;
}