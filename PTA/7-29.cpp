#include<bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int p = a.find(b);
	int lenb = b.size();
	while (p != string::npos) {
		a.erase(p, lenb);
		p = a.find(b);
	}
	cout << a << endl;
	return 0;
}