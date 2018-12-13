#include <iostream>
using namespace std;

int main() {
	int n, n_100, n_10, n_1;
	scanf("%d", &n);
	n_100 = n / 100;
	n_10 = n / 10 % 10;
	n_1 = n % 10;
	for (int i = 0; i < n_100; i++)
		printf("B");
	for (int i = 0; i < n_10; i++)
		printf("S");
	for (int i = 0; i < n_1; i++)
		printf("%d", i + 1);
	printf("\n");
	return 0;
}