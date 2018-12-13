#include<bits/stdc++.h>
using namespace std;

int main() {
	string a, b, c;
	cin >> a;
	int flag = 0;
	for (int i = 0; i < 10; i++) {
		b = a;
		c.clear();
		reverse(a.begin(),a.end());
		if (a == b) {
			flag = 1;
			break;
		}
		int len = a.size();
		int add = 0;
		for (int j = 0; j < len; j++) {
			int sum = a[j] - '0' + b[j] - '0' + add;
			add = sum / 10;
			c += to_string(sum % 10);
		}
		if (add)
			c += to_string(add);
		reverse(c.begin(), c.end());
		cout << b << " + " << a << " = " << c << endl;
		a = c;
	}
	if (flag) {
		cout << a << " is a palindromic number." << endl;
	}
	else {
		cout << "Not found in 10 iterations." << endl;
	}
	return 0;
}