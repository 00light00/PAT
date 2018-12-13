#include <bits/stdc++.h>
using namespace std;

int isprime(int n) {
	int re = 1;
	if (n == 2)
		return re;
	if (n % 2 == 0)
		return re = 0;
	for (int i = 3; i*i <= n; i += 2) {
		if (n%i == 0) {
			re = 0;
			break;
		}
	}
	return re;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int>check_list(10010, 0);
	vector<int> op(n+1, 0);
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		check_list[k] = i + 1;
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int check;
		scanf("%d", &check);
		int order = check_list[check];
		printf("%04d: ", check);
		if (order) {
			if (op[order])
				printf("Checked\n");
			else {
				op[order]++;
				if (order == 1) {
					printf("Mystery Award\n");
				}
				else if (isprime(order)) {
					printf("Minion\n");
				}
				else {
					printf("Chocolate\n");
				}
			}
			
		}
		else {
			printf("Are you kidding?\n");
		}
	}
	return 0;
}