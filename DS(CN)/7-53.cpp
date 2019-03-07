#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &seq[i]);
	}
	int p1 = 0, p2 = n, p = 0, cnt = 2 * n;
	for (int i = 0; i < 2 * n && p1 < n && p2 < 2 * n; i++) {
		if (seq[p1] < seq[p2]) {
			p1++;
		}
		else if (seq[p1] > seq[p2]) {
			p2++;
		}
		else {
			cnt--;
			p1++;
			p2++;
		}
	}
	p1 = 0, p2 = n;
	for (int i = 1; i <= (cnt + 1) / 2; i++) {
		if (seq[p1] < seq[p2]) {
			p = p1;
			p1++;
		}
		else if(seq[p1] > seq[p2]) {
			p = p2;
			p2++;
		}
		else {
			p++;
			p1++;
			p2++;
		}
	}
	printf("%d\n", seq[p]);
	return 0;
}