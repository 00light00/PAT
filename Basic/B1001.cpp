#include <iostream>
using namespace std;

typedef long long ll;

void solve() {
	ll A, B, C;
	int re = 0;
	scanf("%lld %lld %lld", &A, &B, &C);
	if (A > 0 && B > 0 && (A + B) < 0)
		re = 1;
	else if (A < 0 && B < 0 && A + B>0)
		re = 0;
	else {
		if (A + B > C)
			re = 1;
		else
			re = 0;
	}

	if (re)
		printf("true\n");
	else
		printf("false\n");
}

int main() {

	int T;
	scanf("%d", &T);
	for (int i = 0;i < T;i++) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}