#include<bits/stdc++.h>
using namespace std;

double expression(int & flag) {
	string s;
	cin >> s;
	if (s.size() == 1) {
		switch (s[0]) {
		case '+':
			return expression(flag) + expression(flag);
		case '-':
			return expression(flag) - expression(flag);
		case '*':
			return expression(flag)*expression(flag);
		case '/':
		{
			double a = expression(flag);
			double b = expression(flag);
			if (fabs(b) < 1e-5) {
				b = 1;
				flag = 1;
			}
			return a / b;
		}
		default:
			return stod(s);
		}
	}
	else {
		return stod(s);
	}
}

int main() {
	int flag = 0;
	double re = expression(flag);
	if (flag) {
		printf("ERROR\n");
	}
	else
		printf("%.1f\n", re);
	return 0;
}