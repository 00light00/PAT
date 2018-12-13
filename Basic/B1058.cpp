#include <bits/stdc++.h>
using namespace std;

struct question {
	int score, num, num_true;
	string right_answer;
};

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<question> que(m);
	vector<int> cnt(m, 0);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &que[i].score, &que[i].num, &que[i].num_true);
		for (int j = 0; j < que[i].num_true; j++) {
			string tmp;
			cin >> tmp;
			que[i].right_answer += tmp;
		}
	}
	getchar();

	for (int i = 0; i < n; i++) {
		int score = 0;
		for (int j = 0; j < m; j++) {
			int num;
			string ri, num_s, right;
			cin >> num_s;
			num = num_s[1] - '0';
			for (int i = 0; i < num; i++) {
				cin >> right;
				ri.push_back(right[0]);
			}
			if (ri != que[j].right_answer)
				cnt[j]++;
			else
				score += que[j].score;
		}
		printf("%d\n", score);
	}

	int max = *max_element(cnt.begin(), cnt.end());
	if (max) {
		printf("%d", max);
		for (int i = 0; i < m; i++) {
			if (cnt[i] == max)
				printf(" %d", i + 1);
		}
	}
	else
		printf("Too simple");
	printf("\n");
	return 0;
}