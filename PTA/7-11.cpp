#include<bits/stdc++.h>
using namespace std;

int main() {
	int x;
	scanf("%d", &x);
	double re;
	if (x <= 15)
		re = 4.0*x / 3;
	else
		re = 2.5*x - 17.5;
	printf("%.2f\n", re);
	return 0;
}