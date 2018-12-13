#include<bits/stdc++.h>
using namespace std;
//
//struct wrong_cnt{
//	int que_id, ans_id, cnt;
//
//};

int main() {
	int n, m, wrong_maxc = 0;
	scanf("%d %d", &n, &m);
	vector<vector<int> >check, wrong;
	vector<int> score;
	vector<int> tmp(1, 0);
	check.push_back(tmp);
	wrong.push_back(tmp);
	score.push_back(0);
	for (int i = 0; i < m; i++) {
		int score_t, num_q, num_r;
		scanf("%d %d %d", &score_t, &num_q, &num_r);
		score.push_back(score_t);
		vector<int>que(num_q + 1, 0);
		vector<int>wro(num_q + 1, 0);
		que[0] = num_q;
		wro[0] = num_q;
		for (int j = 0; j < num_r; j++) {
			string ans;
			cin >> ans;
			que[ans[0] - 'a' + 1]++;
		}
		check.push_back(que);
		wrong.push_back(wro);
	}
	getchar();
	for (int i = 0; i < n; i++) {
		double score_st = 0;
		for (int j = 1; j <= m; j++) {
			int num_a, wrong_c = 0, miss_c = 0;
			vector<int> checklist(check[j][0] + 1, 0);
			scanf("(%d", &num_a);
			for (int k = 0; k < num_a; k++) {
				string ans;
				cin >> ans;
				checklist[ans[0] - 'a' + 1]++;
				
			}
			for (int k = 1; k <= check[j][0]; k++) {
				if (check[j][k] != checklist[k]) {
					wrong[j][k]++;
					if (wrong_maxc < wrong[j][k])
						wrong_maxc = wrong[j][k];
					if (check[j][k] == 0)
						wrong_c++;
					else
						miss_c++;
				}
			}
			if (wrong_c == 0) {
				if (miss_c) {
					score_st += score[j] / 2.0;
				}
				else
					score_st += score[j];
			}
			getchar();
		}
		printf("%.1f\n", score_st);
	}
	if (wrong_maxc) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= wrong[i][0]; j++) {
				if (wrong[i][j]==wrong_maxc)
					printf("%d %d-%c\n", wrong_maxc, i, j + 'a' - 1);

			}
		}
	}
	else
		printf("Too simple\n");
	return 0;
}