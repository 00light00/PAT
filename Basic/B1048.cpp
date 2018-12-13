#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX = 110;
char change[MAX] = "0123456789JQK";
char a[MAX], b[MAX];

char run(int i) {
	int na = a[i] - '0', nb = b[i] - '0';
	if (b[i] == 0)
		nb = 0;
	if (a[i] == 0)
		na = 0;
	char re;
	if (i % 2) {
		if (nb - na < 0)
			re = nb - na + 10 + '0';
		else
			re = nb - na + '0';
	}
	else {
		re = change[(na + nb) % 13];
	}
	return re;
}

int main() {
	cin >> a >> b;
	int lena = strlen(a), lenb = strlen(b);
	reverse(a, a + lena);
	reverse(b, b + lenb);
	if (lena < lenb) {
		for (int i = lena; i < lenb; i++) {
			a[i] = change[0];
		}
	}
	else if (lenb < lena) {
		for (int i = lenb; i < lena; i++) {
			b[i] = change[0];
		}
	}

	int len = max(lena, lenb);
	for (int p = 0; p < len; p++) {
		b[p] = run(p);
	}

	reverse(b, b + len);
	cout << b << endl;
	return 0;
}