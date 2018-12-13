#include <iostream>
using namespace std;

const int MAX = 10;
int cnt[MAX];

int main() {
	for (int i = 0; i < MAX; i++) {
		scanf("%d", &cnt[i]);
	}
	for (int i = 1; i < MAX; i++) {
		if (cnt[i]) {
			cnt[i]--;
			printf("%d", i);
			break;
		}
	}

	for (int i = 0; i < MAX; i++) {
		if (cnt[i]) {
			for (int j = 0; j < cnt[i]; j++) {
				printf("%d", i);
			}
		}
	}
	return 0;
}