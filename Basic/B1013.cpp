#include <iostream>
using namespace std;

const int MAX = 10;
int cnt[MAX];

int main() {
	for (int i = 0;i < 10;i++) {
		scanf("%d", &cnt[i]);
	}

	for (int i = 1;i < 10;i++) {
		if (cnt[i]) {
			cnt[i]--;
			printf("%d", i);
			break;
		}
	}

	for (int i = 0;i < 10;i++) {
		while (cnt[i]) {
			cnt[i]--;
			printf("%d", i);
		}
	}

	printf("\n");
	return 0;
}