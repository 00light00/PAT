#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 10010;
vector<int> isprime(MAX, 1);

int main() {
	isprime[1] = 0;
	for (int i = 2; i*i < MAX; i++) {
		for (int j = 2; i*j < MAX; j++) {
			isprime[i*j] = 0;
		}
	}
	int msize, n, m;
	scanf("%d %d %d", &msize, &n, &m);
	while (!isprime[msize]) {
		msize++;
	}
	vector<ll> hash(msize, 0);
	for (int i = 0; i < n; i++) {
		ll num, flag = 0;
		scanf("%lld", &num);
		for (int j = 0; j < msize; j++) {
			int pos = (num%msize + j * j) % msize;
			if (!hash[pos]) {
				flag = 1;
				hash[pos] = num;
				break;
			}
		}
		if (!flag)
			printf("%ld cannot be inserted.\n", num);
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		ll num, j;
		scanf("%lld", &num);
		for (j = 0; j <= msize; j++) {
			cnt++;
 			int pos = (num%msize + j * j) % msize;
			if (!hash[pos] || hash[pos] == num) {
				break;
			}
		}
	}

	printf("%.1f\n", cnt*1.0 / m);
	return 0;
}