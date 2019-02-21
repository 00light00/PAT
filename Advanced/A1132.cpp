#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string z, a, b;
		cin >> z;
		a = z.substr(0, z.size() / 2);
		b = z.substr(z.size() / 2);
		int flag = 0;
		if (stoll(a)*stoll(b) <= 0)
			flag = 0;
		else if (stoll(z) % (stoll(a)*stoll(b)) == 0)
			flag = 1;
		if(flag)
			printf("Yes\n");
		else 
			printf("No\n");
	}
	return 0;
}