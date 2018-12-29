#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, sum = 0;
	scanf("%d %d", &a, &b);
	for (int i = 0; i <= b - a; i++) {
		if (i > 0 && i % 5 == 0)
			printf("\n");
		printf("%5d", i + a);
		sum += i + a;
	}
	printf("\n");
	printf("Sum = %d\n", sum);
	return 0;
}