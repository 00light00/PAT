#include <iostream>
using namespace std;

const int MAX = 1010;
char digit[MAX];
int cnt[10];


int main() {
	scanf("%s", digit);
	for (int i = 0;digit[i];i++) {
		int tmp = digit[i] - '0';
		cnt[tmp]++;
	}

	for (int i = 0;i < 10;i++) {
		if (cnt[i])
			printf("%d:%d\n", i, cnt[i]);
	}
	return 0;
}