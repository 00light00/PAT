#include<iostream>
#include<string>
using namespace std;

int check(string& pass) {
	int re = 0, flag_num = 0, flag_alpha = 0;
	int len = pass.length();
	if (len < 6)
		return re = 1;
	for (int i = 0; i < len; i++) {
		if (pass[i] >= '0'&&pass[i] <= '9') {
			flag_num++;
		}
		else if (isalpha(pass[i]))
			flag_alpha++;
		else if (pass[i] == '.') { ; }
		else {
			return re = 2;
		}
	}

	if (flag_alpha&&!flag_num)
		return re = 3;
	if (flag_num&&!flag_alpha)
		return re = 4;
	return re;
}

int main() {
	string pass;
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin, pass);
		switch (check(pass)) {
		case 0:
			cout << "Your password is wan mei." << endl;
			break;
		case 1:
			cout << "Your password is tai duan le." << endl;
			break;
		case 2:
			cout << "Your password is tai luan le." << endl;
			break;
		case 3:
			cout << "Your password needs shu zi." << endl;
			break;
		case 4:
			cout << "Your password needs zi mu." << endl;
			break;
		}
	}

	return 0;
}
