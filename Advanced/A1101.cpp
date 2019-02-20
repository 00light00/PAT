#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector <long long> num1, num2, re;
	for (int i = 0; i < n; i++) {
		long long tmp;
		scanf("%ld", &tmp);
		num1.push_back(tmp);
		num2.push_back(tmp);
	}
	sort(num2.begin(), num2.end());
	int cnt = 0, max = 0;
	for (int i = 0; i < n; i++) {
		max = num1[i] > max ? num1[i] : max;
		if (num1[i] == num2[i] && num2[i] >= max) {
			cnt++;
			re.push_back(num1[i]);
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		if (i > 0)
			printf(" ");
		printf("%d", re[i]);
	}
	printf("\n");
	return 0;
}