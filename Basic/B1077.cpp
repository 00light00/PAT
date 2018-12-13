#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int tec, sum = 0, cnt = 0, min = m, max = 0;
		scanf("%d", &tec);
		for (int j = 1; j < n; j++) {
			int score;
			scanf("%d", &score);
			if (score >= 0 && score <= m) {
				cnt++;
				sum += score;
				min = score < min ? score : min;
				max = max < score ? score : max;
			}
		}
		double score_t = ((sum - min - max) / (cnt - 2.0) + tec) / 2.0 + 0.5;
		printf("%d\n", (int)score_t);
	}
	return 0;
}