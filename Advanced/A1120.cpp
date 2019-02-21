#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	set<int> re;
	for (int i = 0; i < n; i++) {
		string num;
		cin >> num;
		int fnum = 0;
		for (auto it = num.begin(); it != num.end(); it++) {
			fnum += *it - '0';
		}
		re.insert(fnum);
	}

	printf("%d\n", re.size());
	for (auto it = re.begin(); it != re.end(); it++) {
		if (it != re.begin())
			printf(" ");
		printf("%d", *it);
	}
	printf("\n");
	return 0;
}