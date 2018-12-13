#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	int re = a%b;
	while (re > 0){
		a = b;
		b = re;
		re = a % b;
	}
	return b;
}

int main() {
	int min_t, min_d, max_t, max_d, re_d;
	scanf("%d/%d %d/%d %d", &min_t, &min_d, &max_t, &max_d, &re_d);
	if (min_t*max_d > max_t*min_d){
		swap(min_t, max_t);
		swap(min_d, max_d);
	}
	int min = min_t * 1.0 / min_d * re_d - 1;
	int max = max_t * 1.0 / max_d * re_d + 1;
	while(min*min_d <= min_t*re_d)
		min++;
	while(max*max_d >= max_t*re_d)
		max--;
	int flag = 1;
	for (int i = min; i <= max; i++) {
		if (gcd(i, re_d) == 1) {
			if (flag)
				flag = 0;
			else
				printf(" ");
			printf("%d/%d", i, re_d);
		}
	}
	printf("\n");
	return 0;
}