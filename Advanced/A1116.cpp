#include<bits/stdc++.h>
using namespace std;

const int MAX = 10010;
vector<int>isprime(MAX, 1);

int main() {
	isprime[0] = isprime[1] = 0;
	for (int i = 2; i*i < MAX; i++) {
		for (int j = 2; i*j < MAX; j++) {
			isprime[i*j] = 0;
		}
	}

	int n, k;
	scanf("%d", &n);
	map<int, int> rank, visit;
	for (int i = 1; i <= n; i++) {
		int id;
		scanf("%d", &id);
		rank[id] = i;
	}

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int query;
		scanf("%d", &query);
		printf("%04d: ", query);
		if (rank.find(query) != rank.end()) {
			if (visit[query]) {
				printf("Checked\n");
				continue;
			}
			visit[query] = 1;
			int ra = rank[query];
			if (ra == 1) {
				printf("Mystery Award\n");
			}
			else if (isprime[ra]) {
				printf("Minion\n");
			}
			else {
				printf("Chocolate\n");
			}
		}
		else {
			printf("Are you kidding?\n");
		}
	}
	return 0;
}