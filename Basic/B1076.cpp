#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int > re;
	for (int i = 0; i < n; i++) {
		string ans;
		for (int j = 0; j < 4; j++) {
			cin >> ans;
			if (ans[2] == 'T')
				re.push_back(ans[0] - 'A' + 1);
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d", re[i]);
	}
	printf("\n");
	return 0;
}