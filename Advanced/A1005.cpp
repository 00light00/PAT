#include<bits/stdc++.h>
using namespace std;

string number[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

int main() {
	string num;
	cin >> num;
	int len = num.size();
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += num[i] - '0';
	}

	int flag = 0;
	for (int i = 100; i > 0; i /= 10) {
		int num_out = sum / i;
		if (num_out) {
			if (flag)
				cout << " ";
			cout << number[num_out];
			flag = 1;
		}
		else {
			if (flag) {
				cout << " ";
				cout << number[num_out];
				flag = 1;
			}
		}
		sum %= i;
	}
	if (!flag)
		cout << number[0];
	return 0;
}