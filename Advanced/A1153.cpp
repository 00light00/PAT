#include<bits/stdc++.h>
using namespace std;

struct stud {
	string id;
	int score;
	stud() {};
	stud(string i, int s) :id(i), score(s) {};
	bool operator<(stud op) const {
		return score != op.score ? score > op.score:id < op.id;
	}
};
struct type3re {
	string site;
	int cnt;
	type3re() {};
	type3re(string s, int c) :site(s), cnt(c) {};
	bool operator<(type3re op) const {
		return cnt != op.cnt ? cnt > op.cnt: site < op.site;
	}
};
set<stud> type1[3];
map<string, int> type2;
map<string, int> type2_cnt;
map<string, map<string, int> > type3;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		char id[20];
		int score;
		scanf("%s %d", id, &score);
		switch (id[0]) {
		case 'T':
			type1[0].insert(stud(id, score));
			break;
		case 'A':
			type1[1].insert(stud(id, score));
			break;
		case 'B':
			type1[2].insert(stud(id, score));
			break;
		}
		string site(id + 1, 3), date(id + 4, 6);
		type2[site] += score;
		type2_cnt[site]++;
		type3[date][site]++;
	}

	for (int i = 0; i < m; i++) {
		int query;
		char command[20];
		scanf("%d %s", &query, command);
		printf("Case %d: %d %s\n", i + 1, query, command);
		string comm(command);
		switch (query) {
		case 1: 
		{
			int index = 0;
			switch (command[0]) {
			case 'T':
				index = 0;
				break;
			case 'A':
				index = 1;
				break;
			case 'B':
				index = 2;
				break;
			}

			if (type1[index].size()) {
				for (auto it = type1[index].begin(); it != type1[index].end(); it++)
					printf("%s %d\n", it->id.c_str(), it->score);
			}
			else {
				printf("NA\n");
			}
		}
			break; 
		case 2:
			if (type2_cnt[comm])
				printf("%d %d\n", type2_cnt[comm], type2[comm]);
			else
				printf("NA\n");
			break;
		case 3:
			auto date_map = type3[comm];
			if (date_map.empty()) {
				printf("NA\n");
			}
			else {
				set<type3re> re;
				for (auto it = date_map.begin(); it != date_map.end(); it++) {
					re.insert(type3re(it->first, it->second));
				}
				for (auto it = re.begin(); it != re.end(); it++)
					printf("%s %d\n", it->site.c_str(), it->cnt);
			}
			break;
		}
	}

	return 0;
}