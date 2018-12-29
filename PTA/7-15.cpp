#include <bits/stdc++.h>
using namespace std;

int main() {
	double thold;
	scanf("%lf", &thold);
	double pi = 1, re = 1;
	int cnt = 1;
	while (re >= thold) {
		re = re * cnt / (2 * cnt + 1);
		pi += re;
		cnt++;
	}
	printf("%.6f\n", pi * 2);
	return 0;
}