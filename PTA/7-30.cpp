#include<bits/stdc++.h>
using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	vector<string> re;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		re.push_back(tmp);
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (re[j] > re[j + 1])
				swap(re[j], re[j + 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << re[i] << endl;
	}
	return 0;
}