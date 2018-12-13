#include<bits/stdc++.h>
using namespace std;

const int MAX = 22;


int main() {
	string jinzhi, a, b, re;
	vector <int> jinzhilist;
	cin >> jinzhi >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	reverse(jinzhi.begin(), jinzhi.end());
	int alen = a.length(), blen = b.length();
	int len = jinzhi.length();
	for (int i = 0; i <len; i++) {
		switch (jinzhi[i]){
		case '0':
			jinzhilist.push_back(10);
			break;
		default:
			jinzhilist.push_back(jinzhi[i] - '0');
		}
	}
	if (alen < blen) {
		swap(alen, blen);
		swap(a, b);
	}
	for (int i = 0; i < len - alen; i++) {
		a.push_back('0');
	}
	for (int i = 0; i < len - blen; i++)
		b.push_back('0');

	int sum = 0, add = 0;
	for (int i = 0; i < len; i++) {
		sum = a[i] - '0' + b[i] - '0' + add;
		add = sum / jinzhilist[i];
		sum %= jinzhilist[i];
		re.push_back(sum + '0');
	}
	re.push_back(add + '0');
	for (int i = len; re[i] == '0'; i--) {
		re.pop_back();
	}
	if (re.size() == 0)
		re.push_back('0');
	reverse(re.begin(), re.end());
	cout << re << endl;
	return 0;
}