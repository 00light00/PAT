#include <iostream>
using namespace std;

const int MAX = 100010;
int score[MAX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int id, sco;
		scanf("%d %d", &id, &sco);
		score[id] += sco;
	}
	int max = score[0], max_id = 0;
	for (int i = 0; i <= n; i++) {
		if (max < score[i]) {
			max = score[i];
			max_id = i;
		}
	}

	printf("%d %d\n", max_id, max);
	return 0;
}