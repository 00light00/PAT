#include<bits/stdc++.h>
using namespace std;

int isprime(int n) {
	int re = 1;
	if (n < 2) {
		re = 0;
	}
	else if (n == 2) {
		re = 1;
	}
	else if (n % 2 == 0) {
		re = 0;
	}
	else {
		for (int i = 3; i*i <= n; i++) {
			if (n%i == 0) {
				re = 0;
				break;
			}
		}
	}
	return re;
}

int main() {
	int n, k;
	string num;
	cin >> n >> k >> num;
	int flag = 1;
	for (int i = 0; i + k - 1 < n; i++) {
		string num_s = num.substr(i, k);
		int num_t = stoi(num_s);
		if (isprime(num_t)) {
			cout << num_s << endl;
			flag = 0;
			break;
		}
		//cout << num_s << endl;
	}

	if (flag)
		cout << "404" << endl;
	return 0;
}