#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<string> re;
	string tmp;
	while (cin >> tmp)
		re.push_back(tmp);
	reverse(re.begin(), re.end());
	for (auto i = re.begin(); i != re.end(); i++) {
		if (i != re.begin())
			cout << " ";
		cout << *i;
	}
	return 0;
}