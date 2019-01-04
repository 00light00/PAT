#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, u, d;
	scanf("%d %d %d", &n, &u, &d);
	int cnt = 0, sum = 0;
	while (sum < n) {
		cnt++;
		sum += u;
		if (sum >= n)
			break;
		sum -= d;
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}