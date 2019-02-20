#include<bits/stdc++.h>
using namespace std;

struct sch {
	string school;
	int cnt;
	int score;
	sch() {
		score = 0;
		cnt = 0;
	}
	sch(string s, int sc, int c) :school(s), score(sc), cnt(c) {};
	bool operator< (sch op)const {
		return score != op.score ? score > op.score:cnt != op.cnt ? cnt < op.cnt : school < op.school;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	map<string, int> re_cnt;
	map<string, double> re_score;
	for (int i = 0; i < n; i++) {
		double score;
		char id[10], school[10];
		scanf("%s %lf %s", id, &score, school);
		for (int j = 0; school[j]; j++)
			if (school[j] >= 'A'&&school[j] <= 'Z')
				school[j] -= 'A' - 'a';
		switch (id[0]) {
		case 'T':
			score *= 1.5;
			break;
		case 'A':
			break;
		case 'B':
			score /= 1.5;
			break;
		}
		re_cnt[school]++;
		re_score[school] += score;
	}
	set<sch>re2;
	for (auto it = re_cnt.begin(); it != re_cnt.end(); it++) {
		string school(it->first);
		int cnt = it->second;
		int score = re_score[school];
		re2.insert(sch(school, score, cnt));
	}
	int cnt = 1, rank = 1, total = -1;
	printf("%d\n", re2.size());
	for (auto it = re2.begin(); it != re2.end(); it++, cnt++) {
		int score = it->score;
		if (score != total) {
			rank = cnt;
			total = score;
		}
		printf("%d %s %d %d\n", rank, it->school.c_str(), score, it->cnt);
	}
	return 0;
}