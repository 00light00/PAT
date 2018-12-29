#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

struct regular {
	int u, d;
	int flag;
	regular(int a, int b) {
		flag = 1;
		if(a!=0)
			flag *= a / abs(a);
		flag *= b / abs(b);
		a = abs(a);
		b = abs(b);
		int g = gcd(a, b);
		u = a / g;
		d = b / g;
	}
	regular operator+(regular op) {
		return regular(flag*u*op.d + op.flag*d * op.u, d*op.d);
	}
};

int main() {
	int n;
	scanf("%d", &n);
	regular sum(0, 1);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d/%d", &a, &b);
		sum = sum + regular(a, b);
	}

	regular av = regular(sum.u, sum.d*n);
	if (av.flag < 0)
		printf("-");
	printf("%d", av.u);
	if (av.d != 1)
		printf("/%d", av.d);
	return 0;
}