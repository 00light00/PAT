#include<bits/stdc++.h>
using namespace std;

struct cmp {
	int total, cnt, id;
	bool operator<(cmp op) {
		return total != op.total ? total > op.total:cnt != op.cnt ? cnt > op.cnt:id < op.id;
	}
};

int main() {
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	vector<vector<int> > rank(n + 1, vector<int>(k + 1, -2));
	vector<int> pro(k + 1);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &pro[i]);
	}
	for (int i = 0; i < m; i++) {
		int id, pro_id, score;
		scanf("%d %d %d", &id, &pro_id, &score);
		rank[id][pro_id] = score > rank[id][pro_id] ? score : rank[id][pro_id];
	}
	vector<int> perfect_cnt(n + 1, 0);
	vector<cmp> re;
	for (int i = 1; i <= n; i++) {
		cmp tmp;
		for (int j = 1; j <= k; j++) {
			if (rank[i][j] >= 0) {
				if (rank[i][0] < 0)
					rank[i][0] = 0;
				rank[i][0] += rank[i][j];
				if (rank[i][j] == pro[j])
					perfect_cnt[i]++;
			}
		}
		tmp.id = i, tmp.cnt = perfect_cnt[i], tmp.total = rank[i][0];
		if (tmp.total >= 0)
			re.push_back(tmp);
	}

	sort(re.begin(), re.end());

	int cnt = 1, r = 1;
	for (auto it = re.begin(); it != re.end(); it++) {
		if (it == re.begin() || (it - 1)->total != it->total)
			r = cnt;
		int id = it->id;
		printf("%d %05d %d", r, id, it->total);
		for (int i = 1; i <= 4; i++) {
			int score = rank[id][i];
			if (score == -2)
				printf(" -");
			else {
				if (score < 0)
					score = 0;
				printf(" %d", score);
			}
		}
		printf("\n");
		cnt++;
	}

	return 0;
}