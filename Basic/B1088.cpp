#include<bits/stdc++.h>
using namespace std;
template<class T1>
void print(int m, T1 a) {
	cout << " ";
	if (m < a)
		cout << "Cong";
	else if (m == a)
		cout << "Ping";
	else
		cout << "Gai";
}

int main(){
	int m, x, y;
	scanf("%d %d %d", &m, &x, &y);
	int a, b, flag = 1;
	for (a = 99; a >= 10; a--) {
		b = a / 10 + a % 10 * 10;
		int delta = abs(a - b);
		double c1, c2;
		c1 = 1.0*delta / x, c2 = 1.0*b / y;
		if (fabs(c1-c2)<1e-6) {
			cout<<a;
			print(m, a);
			print(m, b);
			print(m, c1);
			cout << endl;
			flag = 0;
			break;
		}
	}
	if (flag)
		cout << "No Solution" << endl;
	return 0;
}