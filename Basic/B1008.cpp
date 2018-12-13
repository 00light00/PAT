#include <iostream>
using namespace std;

const int MAX = 110;
int num[MAX];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	m = m % n;
	reverse(num, num + n - m);
	reverse(num + n - m, num + n);
	reverse(num, num + n);
	for (int i = 0; i < n; i++) {
		if (i > 0)
			printf(" ");
		printf("%d", num[i]);
	}
	return 0;
}