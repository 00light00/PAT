#include <iostream>
using namespace std;

long long cnt[3];
const int MAX = 100010;
char pat[MAX];

int main() {
	scanf("%s", pat);
	for (int i = 0; pat[i]; i++) {
		switch (pat[i]) {
		case 'P':
			cnt[0]++;
			cnt[0] %= 1000000007;
			break;
		case 'A':
			cnt[1] += cnt[0];
			cnt[1] %= 1000000007;
			break;
		case 'T':
			cnt[2] += cnt[1];
			cnt[2] %= 1000000007;
			break;
		}
	}

	printf("%d\n", cnt[2]);
	return 0;
}