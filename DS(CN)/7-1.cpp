#include<bits/stdc++.h>
using namespace std;

int main() {
	int K;
	scanf("%d", &K);
	vector<int> re;
	for (int i = 0; i < K; i++) {
		int tmp;
		scanf("%d", &tmp);
		re.push_back(tmp);
	}
	int max = 0, sum = 0;
	for (int i = 0; i < K; i++) {
		sum += re[i];
		max = sum > max ? sum : max;
		if (sum < 0)
			sum = 0;
	}
	printf("%d\n", max);
	return 0;
}