#include <iostream>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b) {
	ll c = a % b;
	while (c) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

struct fenshu {
	ll fenzi, fenmu;
	int flag;
	fenshu(ll z = 0, ll m = 1, int f = 1) :fenzi(z), fenmu(m),flag(f) {
		huajian();
	}
	void huajian() {
		if (fenzi < 0) {
			flag *= -1;
			fenzi *= -1;
		}
		ll g = gcd(fenzi, fenmu);
		fenzi /= g;
		fenmu /= g;
		
	}

	fenshu operator+(fenshu op) {
		return fenshu(fenzi*flag*op.fenmu + fenmu * op.flag * op.fenzi, fenmu*op.fenmu, 1);
	}
	fenshu operator-(fenshu op) {
		op.flag *= -1;
		return *this + op;
	}
	fenshu operator*(fenshu op) {
		return fenshu(fenzi*op.fenzi, fenmu*op.fenmu, flag*op.flag);
	}
	fenshu operator/(fenshu op) {
		swap(op.fenmu, op.fenzi);
		return *this*op;
	}
	void print() {
		if (flag<0) {
			printf("(-");
		}
		if (fenzi) {
			if (fenzi / fenmu)
				printf("%lld", fenzi/fenmu);
			if (fenzi%fenmu) {
				if (fenzi / fenmu)
					printf(" ");
				printf("%lld/%lld", fenzi%fenmu, fenmu);
			}
		}
		else {
			printf("0");
		}

		if (flag<0) {
			printf(")");
		}
	}
};

int main() {
	fenshu a, b, re;
	scanf("%lld/%lld %lld/%lld", &a.fenzi, &a.fenmu, &b.fenzi, &b.fenmu);
	a.huajian();
	b.huajian();
	a.print();

	printf(" + ");
	b.print();
	printf(" = ");
	re = a + b;
	re.print();
	printf("\n");
	a.print();
	printf(" - ");
	b.print();
	printf(" = ");
	re = a - b;
	re.print();
	printf("\n");
	a.print();
	printf(" * ");
	b.print();
	printf(" = ");
	re = a * b;
	re.print();
	printf("\n");
	a.print();
	printf(" / ");
	b.print();
	printf(" = ");
	if (b.fenzi != 0) {
		re = a / b;
		re.print();
	}
	else
		printf("Inf\n");


 	return 0;
}