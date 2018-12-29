#include<bits/stdc++.h>
using namespace std;

vector<int> check(10, 0);

int main() {
	string num, num_2;
	cin >> num;
	reverse(num.begin(), num.end());
	int len = num.size();
	int sum = 0, add = 0;
	for (int i = 0; i < len; i++) {
		int dig = num[i] - '0';
		check[dig]++;

		sum = add + dig * 2;
		add = sum / 10;
		sum %= 10;
		num_2.push_back(sum + '0');
	}
	if (add)
		num_2.push_back(add + '0');
	for (auto i = num_2.begin(); i != num_2.end(); i++) {
		check[*i - '0']--;
	}
	int flag = 1;
	for (int i = 0; i < 10; i++) {
		if (check[i]) {
			flag = 0;
			break;
		}
	}
	reverse(num_2.begin(), num_2.end());
	if (num_2.empty())
		num_2.push_back('0');
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
	cout << num_2 << endl;
	return 0;
}