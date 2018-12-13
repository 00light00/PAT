#include <iostream>
using namespace std;

const int MAX = 1010;
char num[MAX];
int cnt[10];

int main() {
	scanf("%s", num);
	for (int i = 0; num[i]; i++) {
		cnt[num[i] - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		if (cnt[i])
			printf("%d:%d\n", i, cnt[i]);
	}
	return 0;
}
