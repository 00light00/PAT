#include <iostream>
using namespace std;

int a[6];

int main() {
	int n;
	scanf("%d", &n);
	int cnt4 = 0;
	int flag = 1;
	for (int i = 0;i < n;i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp % 10 == 0) {
			a[1] += tmp;
		}

		if (tmp % 5 == 1) {
			a[2] += tmp * flag;
			flag *= -1;
		}

		if (tmp % 5 == 2) {
			a[3]++;
		}

		if (tmp % 5 == 3) {
			a[4] += tmp;
			cnt4++;
		}

		if (tmp % 5 == 4) {
			a[5] = a[5] > tmp ? a[5] : tmp;
		}
	}

	if (a[1])
		printf("%d ", a[1]);
	else
		printf("N ");
	
	if (a[2])
		printf("%d ", a[2]);
	else
		printf("N ");

	if (a[3])
		printf("%d ", a[3]);
	else
		printf("N ");

	if (a[4])
		printf("%.1f ", a[4] * 1.0 / cnt4);
	else
		printf("N ");

	if (a[5])
		printf("%d", a[5]);
	else
		printf("N");

	return 0;
}