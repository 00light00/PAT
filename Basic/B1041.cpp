#include<iostream>
using namespace std;

struct stdu {
	char id[20];
	int shiji, zuowei;
};
const int MAX = 1010;
stdu query[MAX];


int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		stdu tmp;
		scanf("%s %d %d", tmp.id, &tmp.shiji, &tmp.zuowei);
		query[tmp.shiji] = tmp;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int shiji_tmp;
		scanf("%d", &shiji_tmp);
		printf("%s %d\n", query[shiji_tmp].id, query[shiji_tmp].zuowei);
	}

	return 0;
}