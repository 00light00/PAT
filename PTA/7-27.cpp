#include<bits/stdc++.h>
using namespace std;



int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> num(n);
	for (int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (num[j] > num[j + 1])
				swap(num[j], num[j + 1]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (i > 0)
			printf(" ");
		printf("%d", num[i]);
	}
	return 0;
}