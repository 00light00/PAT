#include <iostream>
using namespace std;

const int MAX = 10010;
char test[MAX];
char pat[10] = "PATest";
int cnt[6];

int main() {
	scanf("%s", test);
	for (int i = 0; test[i]; i++) {
		for (int j = 0; pat[j]; j++) {
			if (pat[j] == test[i]) {
				cnt[j]++;
				break;
			}
		}
	}

	int flag = 1;
	while (flag) {
		flag = 0;
		for (int i = 0; pat[i]; i++) {
			if (cnt[i]) {
				printf("%c", pat[i]);
				cnt[i]--;
			}
			flag += cnt[i];
		}
	}
	printf("\n");
	return 0;
}