#include<bits/stdc++.h>
using namespace std;

int main() {
	int bcd, re = 0;
	scanf("%d", &bcd);
	re += bcd % 16;
	re += bcd / 16 * 10;
	printf("%d\n", re);
	return 0;
}