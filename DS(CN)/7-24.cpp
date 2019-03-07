#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	map<string, int> cnt;
	for (int i = 0; i < n; i++) {
		string name;
		getline(cin, name);
		cnt[name]++;
	}

	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		printf("%s %.4f%%\n", it->first.c_str(), it->second*100.0 / n);
	}
	return 0;
}