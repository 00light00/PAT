#include<bits/stdc++.h>
using namespace std;

const int MAX = 100010;


int main() {
	int a, n;
	int add = 0;
	string re;
	scanf("%d %d", &a, &n);
	for (int i = 0; i < MAX; i++) {
		int num;
		if (i <= n)
			num = a * (n - i) + add;
		else
			num = add;
		add = num / 10;
		num %= 10;
		re.push_back(num + '0');
	}
	for (int i = MAX - 1; i >= 0; i--) {
		if (re[i]=='0')
			re.pop_back();
		else
			break;
	}
	if (re.size() == 0)
		re.push_back('0');
	reverse(re.begin(), re.end());
	cout << re << endl;

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000010;
int num[MAX];

int main() {
	int a, n;
	int add = 0;
	scanf("%d %d", &a, &n);
	for (int i = 0; i < MAX; i++) {
		if (i <= n)
			num[i] = a * (n - i) + add;
		else
			num[i] = add;
		add = num[i] / 10;
		num[i] %= 10;
	}
	int flag = 0;
	for (int i = MAX - 1; i >= 0; i--) {
		if (flag || num[i]) {
			flag = 1;
			printf("%d", num[i]);
		}
	}

	if (!flag)
		printf("0");
	return 0;
}