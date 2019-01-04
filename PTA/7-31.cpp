#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	string s;
	getline(cin, s);
	cin >> n;
	int len = s.size();
	n %= len;
	string s1, s2;
	s1 = s.substr(0, n);
	s2 = s.substr(n, len - n);
	cout << s2 + s1 << endl;
	return 0;
}