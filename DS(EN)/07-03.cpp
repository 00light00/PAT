#include<bits/stdc++.h>
using namespace std;

const int MAX = 1010;
int seq[MAX],sta[MAX],check[MAX];
int m, n, k;

bool popcheck();

int main() {
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < n; i++) {
		seq[i] = i + 1;
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &check[j]);
		}
		if (popcheck()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}


bool popcheck() {
	int pcheck = 0, pseq = 0;
	int pstack = -1;
	while (pseq < n) {
		do {
			sta[++pstack] = seq[pseq++];
			if (pstack >= m)
				return false;
		} while (check[pcheck] != sta[pstack]);

		while (pstack > -1 && check[pcheck] == sta[pstack]) {
			pcheck++;
			pstack--;
		}
	}
	if (pstack > -1)
		return false;
	return true;
}