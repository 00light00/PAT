#include<bits/stdc++.h>
using namespace std;

string nian[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };

void fun(int n) {
	if (n > 0) {
		fun(n / 10);
		if (n >= 10)
			cout << " ";
		cout << nian[n % 10];
	}
	return;
}

int main() {
	int num;
	scanf("%d", &num);
	if (num > 0) {
		fun(num);
	}
	else if (num < 0) {
		cout << "fu ";
		fun(num*-1);
	}
	else
		cout << nian[0];
	return 0;
}