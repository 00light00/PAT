#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		sum += tmp;
	}
	int re = sum * (n - 1);
	re += re * 10;
	printf("%d\n", re);
	return 0;
}