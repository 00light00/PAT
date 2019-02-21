#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> mile(n + 1, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &mile[i]);
	}
	
	sort(mile.begin(), mile.end(), greater<int>());
	int day = 0;
	for (int i = 0; i <= n; i++) {
		if (i+1 >= mile[i]) {
			day = i;
			break;
		}
	}
	printf("%d\n", day);
	return 0;
}