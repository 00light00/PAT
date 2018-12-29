#include <bits/stdc++.h>
using namespace std;

int main() {
	int n1, n2;
	char op;
	int re;
	scanf("%d %c %d", &n1, &op, &n2);
	switch (op) {
	case '+':
		re = n1 + n2;
		printf("%d\n", re);
		break;
	case '-':
		re = n1 - n2;
		printf("%d\n", re);
		break;
	case '/':
		re = n1 / n2;
		printf("%d\n", re);
		break;
	case '*':
		re = n1 * n2;
		printf("%d\n", re);
		break;
	case '%':
		re = n1 % n2;
		printf("%d\n", re);
		break;
	default:
		printf("ERROR\n");
	}
	return 0;
}