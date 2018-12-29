#include<bits/stdc++.h>
using namespace std;

int main() {
	int t, distance = 0, sleep = 0;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		if (sleep) {
			distance -= 3;
			sleep--;
		}
		else
			distance += 6;
		if (i % 10==9 && !sleep && distance > 0) {
			sleep = 30;
		}
	}
	if (distance > 0)
		printf("^_^ %d\n", 3 * t + distance);
	else if (distance < 0)
		printf("@_@ %d\n", 3 * t);
	else
		printf("-_- %d\n", 3 * t);
	return 0;
}