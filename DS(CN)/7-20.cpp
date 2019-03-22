#include<bits/stdc++.h>
using namespace std;

void expression0();
void expression1();
void expression2();

int flag = 0;

void expression0() {
	char p = cin.peek();
	if (p == '(') {
		cin.get();
		expression2();
		cin.get();
	}
	else {
		int d;
		cin >> d;
		if (flag)
			cout << " ";
		else
			flag = 1;
		cout << d;
		int more = 1;
		while (more) {
			char p = cin.peek();
			if (p == '.') {
				cin.get();
				cout << p;
				cin >> d;
				cout << d;
			}
			else
				more = 0;
		}
	}
}

void expression1() {
	expression0();
	int more = 1;
	while (more) {

		char p = cin.peek();
		if (p == '*' || p == '/') {
			cin.get();
			expression0();
			cout << " " << p;
		}
		else
			more = 0;
	}
}

void expression2() {
	expression1();
	int more = 1;
	while (more) {

		char p = cin.peek();
		if (p == '+' || p == '-') {
			cin.get();
			expression1();
			cout << " " << p;
		}
		else
			more = 0;
	}
}

int main() {
	expression2();
	return 0;
}