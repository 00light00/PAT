#include<bits/stdc++.h>
using namespace std;

int main() {
	string num;
	cin >> num;
	int flag = 0;
	for (int i = 0; i < 10; i++) {
		string num_r(num);
		reverse(num_r.begin(), num_r.end());
		if (num_r == num) {
			flag = 1;
			break;
		}
		int extra = 0, len = num.size();
		string re;
		for (int j = 0; j < len; j++) {
			int sum = num[j] - '0' + num_r[j] - '0' + extra;
			extra = sum / 10;
			sum %= 10;
			re.push_back('0' + sum);
		}
		if (extra)
			re.push_back('0' + extra);
		reverse(re.begin(), re.end());
		cout << num << " + " << num_r << " = " << re << endl;
		num = re;
	}

	if (flag) {
		cout << num << " is a palindromic number." << endl;
	}
	else {
		cout << "Not found in 10 iterations." << endl;
	}
	return 0;
}