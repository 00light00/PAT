#include<bits/stdc++.h>
using namespace std;

int main() {
	int m, n,a,b,val;
	scanf("%d %d %d %d %d", &m, &n, &a, &b, &val);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int val_t;
			scanf("%d", &val_t);
			if (j > 0)
				printf(" ");
			if (val_t >= a && val_t <= b)
				printf("%03d", val);
			else
				printf("%03d", val_t);
		}
		printf("\n");
	}
	return 0;
}