#include <iostream>
using namespace std;

int main() {
	int da, db;
	long long a, b, pa = 0, pb = 0;
	scanf("%lld %d %lld %d", &a, &da, &b, &db);
	while (a > 0) {
		if(a%10==da)
			pa = pa * 10 + da;
		a /= 10;
	}
	while (b > 0) {
		if (b % 10 == db)
			pb = pb * 10 + db;
		b /= 10;
	}

	printf("%lld", pa + pb);
	return 0;
}