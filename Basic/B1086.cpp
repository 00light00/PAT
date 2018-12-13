#include<bits/stdc++.h>
using namespace std;

int main() { 
	int a, b, plus;
	string re;
	scanf("%d %d", &a, &b);
	plus = a * b;
	re = to_string(plus);
	for (auto it = re.end() - 1; it != re.begin(); it--) {
		if (*it != '0')
			break;
		else
			re.pop_back();
	}
	reverse(re.begin(), re.end());
	cout << re << endl;
	return 0;
}