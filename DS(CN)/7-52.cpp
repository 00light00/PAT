#include<bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<long long, int> seq1;
	vector<long long> re;
	long long num;
	scanf("%lld", &num);
	while (num != -1) {
		seq1[num]++;
		scanf("%lld", &num);
	}

	scanf("%lld", &num);
	while (num != -1) {
		if (seq1[num]) {
			seq1[num]--;
			re.push_back(num);
		}
		scanf("%lld", &num);
	}

	if (re.size()) {
		for (auto it = re.begin(); it != re.end(); it++) {
			if (it != re.begin())
				printf(" ");
			printf("%d", *it);
		}
	}
	else
		printf("NULL\n");
	return 0;
}