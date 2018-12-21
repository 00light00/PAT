#include<bits/stdc++.h>
using namespace std;

int main() {
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int num, num_sq;
		scanf("%d", &num);
		num_sq = num * num;
		int k_check = 1, num_t = num;
		while (num_t > 0) {
			k_check *= 10;
			num_t /= 10;
		}
		int flag = 0;
		for (int j = 1; j < 10; j++) {
			if ((j*num_sq - num) % k_check == 0) {
				flag = 1;
				printf("%d %d\n", j, j*num_sq);
				break;
			}
		}

		if (!flag)
			printf("No\n");
	}
	return 0;
}