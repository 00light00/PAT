#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	vector<int> re;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		re.push_back(num);
	}
	sort(re.begin(), re.end());
	for (int i = 0; i < n; i++) {
		if (i > 0)
			printf(" ");
		printf("%d", re[i]);
	}
	return 0;
}