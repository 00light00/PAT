#include<bits/stdc++.h>
using namespace std;

double a[4];

double f(double x) {
	double re = 0;
	for (int i = 3; i >= 0; i--) {
		re *= x;
		re += a[i];
	}
	return re;
}

int main() {
	for (int i = 3; i >= 0; i--)
		scanf("%lf", &a[i]);
	double L, R;
	scanf("%lf %lf", &L, &R);
	double mid;
	while (R - L > 0.001) {
		mid = (R + L) / 2;
		if (f(mid)*f(R) > 0)
			R = mid;
		else if (f(mid)*f(L) > 0)
			L = mid;
		else if (fabs(f(mid)) < 1e-4)
			break;
	}
	printf("%.2f\n", mid);
	return 0;
}