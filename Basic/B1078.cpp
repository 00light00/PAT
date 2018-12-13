#include<bits/stdc++.h>
using namespace std;

int main() {
	string line, op, re;
	cin >> op;
	getchar();
	getline(cin, line);
	int len = line.size();
	switch (op[0]) {
	case 'C':
	{

		int cnt = 1;
		for (int i = 1; i <= len; i++) {
			if (line[i] == line[i - 1]) {
				cnt++;
			}
			else {
				if (cnt > 1) {
					re += to_string(cnt);
					re += line[i - 1];
				}
				else {
					re += line[i - 1];
				}
				cnt = 1;
			}
		}
	}
		break;
	case 'D':
	{

		int cnt = 0;
		for (int i = 0; i < len; i++) {
			if (line[i] >= '0'&&line[i] <= '9') {
				cnt *= 10;
				cnt += line[i] - '0';
			}
			else {
				if (!cnt)
					cnt++;
				for (int j = 0; j < cnt; j++) {
					re += line[i];
				}
				cnt = 0;
			}
		}
	}
		break;
	}
	cout << re << endl;
	return 0;
}