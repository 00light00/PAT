#include<bits/stdc++.h>
using namespace std;

const int MAX = 10010;
vector<int> isprime(MAX, 1);

int main() {
	isprime[0] = isprime[1] = 0;
	for (int i = 2; i*i < MAX; i++) {
		for (int j = 2; i*j < MAX; j++) {
			isprime[i*j] = 0;
		}
	}
	int m, n;
	scanf("%d %d", &m, &n);
	while (!isprime[m]) { m++; }
	vector<int> hasht(m, -1);
	for (int i = 0; i < n; i++) {
		int num, v;
		scanf("%d", &num);
		v = num % m;
		int pos = -1;
		for (int j = 0; j < n; j++) {
			if (hasht[(v + j * j) % m] < 0) {
				hasht[(v%m + j * j) % m] = num;
				pos = (v%m + j * j) % m;
				break;
			}
		}
		if (i > 0)
			printf(" ");
		if (pos > -1)
			printf("%d", pos);
		else
			printf("-");
	}
	return 0;
}