#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	queue<int> quea, queb;
	vector<int> re;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		if (num % 2)
			quea.push(num);
		else
			queb.push(num);
	}

	for (int i = 0; !quea.empty() || !queb.empty(); i++) {
		if (i % 2) {
			if (!quea.empty()) {
				re.push_back(quea.front());
				quea.pop();
			}
			if (!queb.empty()) {
				re.push_back(queb.front());
				queb.pop();
			}
		}
		else {
			if (!quea.empty()) {
				re.push_back(quea.front());
				quea.pop();
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i > 0)
			printf(" ");
		printf("%d", re[i]);
	}
	return 0;
}