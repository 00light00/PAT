#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string calc;
	getline(cin, calc);
	int len = calc.length(), sum = 0;
	for (int i = 0; i < len; i++) {
		if (calc[i] >= 'a'&&calc[i] <= 'z') {
			sum += calc[i] - 'a' + 1;
		}
		else if (calc[i] >= 'A'&&calc[i] <= 'Z') {
			sum += calc[i] - 'A' + 1;
		}
	}

	vector<int> cnt(2, 0);
	while (sum) {
		cnt[sum % 2]++;
		sum /= 2;
	}
	printf("%d %d\n", cnt[0], cnt[1]);
	return 0;
}