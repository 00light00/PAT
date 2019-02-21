#include<bits/stdc++.h>
using namespace std;

int main() {
	int k;
	string keyboard, re;
	cin >> k;
	getchar();
	getline(cin, keyboard);
	int len = keyboard.size();
	int cnt = 1;
	map<char, int> check;
	for (int i = 1; i <=len; i++) {
		if (keyboard[i] != keyboard[i - 1]) {
			if (cnt % k) {
				check[keyboard[i - 1]] = 1;
			}
			else
				re.push_back(keyboard[i - 1]);
			cnt = 1;
		}
		else
			cnt++;
	}
	cnt = 1;
	for (int i = len - 1; i >= 0; i--) {
		if (keyboard[i] != keyboard[i + 1]) {
			if (cnt % k==0 && !check[keyboard[i + 1]]) {
				keyboard.erase(i + 1, cnt - cnt / k);
			}
			cnt = 1;
		}
		else
			cnt++;

	}

	for (int i = 0; re[i]; i++) {
		if (!check[re[i]]) {
			printf("%c", re[i]);
			check[re[i]] = 1;
		}
	}
	printf("\n");
	cout << keyboard << endl;
	return 0;
}