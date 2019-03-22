#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> vip;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		char id[20];
		int length;
		scanf("%s %d", id, &length);
		length = length < k ? k : length;
		vip[id] += length;
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		char id[20];
		scanf("%s", id);
		if (vip[id])
			printf("%d\n", vip[id]);
		else
			printf("No Info\n");
	}
	return 0;
}