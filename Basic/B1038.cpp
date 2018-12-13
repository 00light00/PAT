#include <iostream>
using namespace std;

const int MAX = 110;
int score[MAX];

int main() {
	int n, k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		score[tmp]++;
	}

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (i > 0)
			printf(" ");
		printf("%d", score[tmp]);
	}
	return 0;
}