#include<bits/stdc++.h>
using namespace std;

const int cnt = 51;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> age_c(cnt, 0);
	for (int i = 0; i < n; i++) {
		int age;
		scanf("%d", &age);
		age_c[age]++;
	}
	for (int i = 0; i < cnt; i++) {
		if (age_c[i])
			printf("%d:%d\n", i, age_c[i]);
	}
	return 0;
}