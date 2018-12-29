#include<bits/stdc++.h>
using namespace std;

int main() {
	string se;
	getline(cin, se);
	int cnt = 0, flag = 0;
	for (auto i = se.begin(); i != se.end(); i++) {
		if (*i == ' ' || *i == '.') {
			if (cnt) {
				if (flag)
					printf(" ");
				else
					flag = 1;
				printf("%d", cnt);
			}
			cnt = 0;
		}
		else
			cnt++;
	}
	return 0;
}