#include <iostream>
using namespace std;

const int MAX = 1010;
int cnt[MAX];
char dst[MAX], src[MAX];

int main() {
	scanf("%s", src);
	scanf("%s", dst);
	for (int i = 0; dst[i]; i++) {
		cnt[dst[i]]--;
	}
	for (int i = 0; src[i]; i++) {
		cnt[src[i]]++;
	}
	int sum = 0, sum_minus = 0, flag = 1;
	for (int i = 0; i < MAX; i++) {
		if (cnt[i] < 0) {
			flag = 0;
			sum_minus += cnt[i];
		}
		else if (cnt[i] > 0) {
			sum += cnt[i];
		}
	}

	if (flag) {
		printf("Yes %d\n", sum);
	}
	else {
		printf("No %d\n", -sum_minus);
	}
	return 0;
}