#include <iostream>
using namespace std;

const int MAX = 1010;
int team[MAX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int team_no, mem_no, score;
		scanf("%d-%d %d", &team_no, &mem_no, &score);
		team[team_no] += score;
	}
	int max_id = 0, max = team[max_id];
	for (int i = 0; i < MAX; i++) {
		if (max < team[i]) {
			max = team[i];
			max_id = i;
		}
	}
	printf("%d %d\n", max_id, max);
	return 0;
}