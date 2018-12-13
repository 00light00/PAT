#include<bits/stdc++.h>
using namespace std;

int main() {
	int m, n, s;
	scanf("%d %d %d", &m, &n, &s);
	vector<string> name;
	for (int i = 0; i < m; i++) {
		string person;
		cin >> person;
		name.push_back(person);
	}
	vector<string>re;
	set<string>re_set;
	for (int i = s - 1; i < m; i += n) {
		set<string>::iterator it = re_set.find(name[i]);
		while (it != re_set.end()) {
			it = re_set.find(name[++i]);
		}
		re.push_back(name[i]);
		re_set.insert(name[i]);
	}

	int len = re.size();
	if (len) {
		for (int i = 0; i < len; i++)
			cout << re[i] << endl;
	}
	else
		cout << "Keep going..." << endl;

	return 0;
}