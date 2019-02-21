#include<bits/stdc++.h>
using namespace std;

int main() {
	int m, n, s;
	vector<string> lst, re;
	cin >> m >> n >> s;
	map<string,int> hash;
	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		lst.push_back(name);
	}

	for (int i = s - 1; i < m; i += n) {
		while (i < m && hash[lst[i]]) {
			i++;
		}
		if (i >= m)
			break;
		re.push_back(lst[i]);
		hash[lst[i]]++;		
	}

	if (re.empty())
		cout << "Keep going..." << endl;
	else {
		for (auto it = re.begin(); it != re.end(); it++) {
			cout << *it << endl;
		}
	}
	return 0;
}