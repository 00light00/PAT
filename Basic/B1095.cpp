#include<bits/stdc++.h>
using namespace std;

struct stud {
	string id;
	int score;
	stud() {};
	stud(string i, int s) :id(i), score(s) {};
	bool operator<(const stud &cmp)const {
		return score == cmp.score ? id < cmp.id : score>cmp.score;
	}
};

struct place_c {
	int place, cnt;
	place_c() {};
	place_c(int p, int c) :place(p), cnt(c) {};
	bool operator<(const place_c &cmp)const {
		return cnt == cmp.cnt ? place<cmp.place : cnt>cmp.cnt;
	}
};
const int MAX = 1010;

int main() {
	int n, m;
	cin >> n >> m;
	vector<stud> kind1[3];
	vector<int>kind2(MAX, 0), kind2_cnt(MAX, 0);
	map<string, map<int, int> > kind3;

	for (int i = 0; i < n; i++) {
		string id;
		int score;
		cin >> id >> score;
		switch (id[0]) {
		case 'T':
			kind1[0].push_back(stud(id, score));
			break;
		case 'A':
			kind1[1].push_back(stud(id, score));
			break;
		case 'B':
			kind1[2].push_back(stud(id, score));
			break;
		}
		int place_id = stoi(id.substr(1, 3));
		string date = id.substr(4, 6);
		kind2[place_id] += score;
		kind2_cnt[place_id]++;
		kind3[date][place_id]++;
	}
	for (int i = 0; i < 3; i++) {
		sort(kind1[i].begin(), kind1[i].end());
	}
	for (int i = 1; i <= m; i++) {
		int kind;
		string command;
		cin >> kind >> command;
		printf("Case %d: %d %s\n", i, kind, command.c_str());
		switch (kind) {
		case 1:
		{
			int k = 0;
			switch (command[0]) {
			case 'T':
				k = 0;
				break;
			case 'A':
				k = 1;
				break;
			case 'B':
				k = 2;
				break;
			}
			if (kind1[k].size()) {
				for (auto i = kind1[k].begin(); i != kind1[k].end(); i++) {
					printf("%s %d\n", i->id.c_str(), i->score);
				}
			}
			else
				printf("NA\n");
		}
			break;
		case 2:
		{
			int place_id = stoi(command);
			if (kind2_cnt[place_id])
				printf("%d %d\n", kind2_cnt[place_id], kind2[place_id]);
			else
				printf("NA\n");
		}
			break;
		case 3:
			vector<place_c> re;
			for (auto i = kind3[command].begin(); i != kind3[command].end(); i++)
				re.push_back(place_c(i->first, i->second));
			if (re.size()) {
				sort(re.begin(), re.end());
				for (auto i = re.begin(); i != re.end(); i++)
					printf("%d %d\n", i->place, i->cnt);
			}
			else {
				printf("NA\n");
			}
			break;
		}
	}

	return 0;
}