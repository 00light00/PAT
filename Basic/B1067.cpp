#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string password;
	cin >> password >> n;
	int flag = 1;
	getchar();
	while (n--) {
		string check;
		getline(cin, check);
		if (check == "#") {
			flag = 0;
			break;
		}
		else if (check == password) {
			cout << "Welcome in" << endl;
			flag = 0;
			break;
		}
		else {
			cout << "Wrong password: " << check << endl;
		}
	}
	if (flag)
		cout << "Account locked" << endl;
	return 0;
}