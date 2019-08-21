#include<bits/stdc++.h>
using namespace std;

const int MAX = 10100;
vector<int> isprime(MAX, 1);

int main() {
	isprime[1] = 0;
	for (int i = 2; i*i < MAX; i++) {
		for (int j = 2; i*j < MAX; j++) {
			isprime[i*j] = 0;
		}
	}

	int n, m, size;
	scanf("%d %d", &m, &n);
	size = m;
	while (!isprime[size]) {
		size++;
	}
	vector<int> hash(size, -1);
	for (int i = 0; i < n; i++) {
		if (i > 0)
			printf(" ");
		int num;
		scanf("%d", &num);
		num %= size;
		int increase = 0, flag = 1;
		while (increase < size) {
			int pos = num + increase * increase;
			pos %= size;
			if (hash[pos] == -1) {
				hash[pos] = num;
				flag = 0;
				printf("%d", pos);
				break;
			}
			increase++;
		}
		if (flag)
			printf("-");
	}
	return 0;
}