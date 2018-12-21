#include<bits/stdc++.h>
using namespace std;

const int MAX = 256;

int main() {
	string A, B, re;
	vector<int>check(MAX, 0);
	getline(cin, A);
	getline(cin, B);
	for (auto i = A.begin(); i != A.end(); i++) {
		if (!check[*i]) {
			re.push_back(*i);
			check[*i]++;
		}
	}
	for (auto i = B.begin(); i != B.end(); i++) {
		if (!check[*i]) {
			re.push_back(*i);
			check[*i]++;
		}
	}
	cout << re << endl;
	return 0;
}