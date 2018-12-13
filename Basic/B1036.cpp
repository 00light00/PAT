#include <iostream>
using namespace std;

int main() {
	int n;
	char c;
	scanf("%d %c", &n, &c);

	for (int i = 1; i <= (n + 1) / 2; i++) {
		if (i == 1 || i == (n + 1) / 2) {
			for (int j = 0; j < n; j++)
				printf("%c", c);
			printf("\n");
		}
		else {
			printf("%c", c);
			for (int j = 1; j < n - 1; j++) {
				printf(" ");
			}
			printf("%c\n", c);
		}
	}
	return 0;
}