#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, d;
	scanf("%d %d", &d, &n);
	string num;
	num.push_back(d + '0');
	for (int i = 1; i < n; i++) {
		string numt;
		int size = num.size();
		int cnt = 1;
		for (int j = 0; j < size; j++) {
			if (num[j] == num[j + 1]) {
				cnt++;
			}
			else {
				numt.push_back(num[j]);
				numt.push_back(cnt + '0');
				cnt = 1;
			}
		}
		num = numt;
	}
	cout << num << endl;
	return 0;
}