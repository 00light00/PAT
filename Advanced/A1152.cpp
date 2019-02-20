#include<bits/stdc++.h>
using namespace std;

int isprime(string p) {
	int re = 1;
	long long prime = stoll(p);
	if (prime == 2)
		re = 1;
	else if (prime % 2 == 0)
		re = 0;
	else {
		for (int i = 3; i*i <= prime; i += 2) {
			if (prime % i == 0) {
				re = 0;
				break;
			}
		}
	}
	return re;
}


int main() {
	int l, k;
	string num;
	cin >> l >> k;
	getchar();
	getline(cin, num);
	int flag = 0;
	for (int i = 0; i <= l - k; i++) {
		string prime = num.substr(i, k);
		if (isprime(prime)) {
			flag = 1;
			cout << prime << endl;
			break;
		}
	}
	if (!flag)
		cout << "404" << endl;
	return 0;
}