#include <iostream>
using namespace std;

const int MAX = 1010;
char a[MAX];

int main() {
	int b, r=0;
	scanf("%s %d", a, &b);
	for (int i = 0; a[i]; i++) {
		r = r * 10 + a[i] - '0';
		a[i] = r / b + '0';
		r %= b;
	}
	int flag = 1;
	for (int i = 0; a[i]; i++) {
		if (a[i] == '0'&&flag)
			continue;
		if (a[i] != '0')
			flag = 0;
		printf("%c", a[i]);

	}
	if (flag)
		printf("0");
	printf(" %d\n", r);
	return 0;
}