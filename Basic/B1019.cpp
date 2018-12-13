#include<iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	do {
		int num[4];
		int cnt = 1;
		for (int i = 0; i < 4; i++) {
			num[i] = n / cnt % 10;
			cnt *= 10;
		}
		sort(num, num + 4);
		int max = 0, min = 0;
		for (int i = 0; i < 4; i++) {
			max = max * 10 + num[3 - i];
			min = min * 10 + num[i];
		}
		n = max - min;
		printf("%04d - %04d = %04d\n", max, min, n);
	} while (n != 0 && n != 6174);

	return 0;
}