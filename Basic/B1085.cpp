#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct school {
	string name;
	double score;
	int score_i;
	int num;
	school(string n, double s = 0, int nu = 0) :name(n), score(s), num(nu) { score_i = score; }
	school() {};
	bool operator<(const school& cmp)const {
		return score_i == cmp.score_i ? (num == cmp.num ? (name < cmp.name) : num < cmp.num) : score_i > cmp.score_i;
	}
};


int main() {
	int n;
	scanf("%d", &n);
	unordered_map<string, double> check1;
	unordered_map<string, int> check2;
	for (int i = 0; i < n; i++) {
		string id, _name;
		int _score;
		cin >> id >> _score >> _name;
		int flag = 1;
		for (int j = 0; _name[j]; j++) {
			if (_name[j] >= 'A'&&_name[j] <= 'Z')
				_name[j] = _name[j] - 'A' + 'a';
		}
		double add;
		switch (id[0]) {
		case 'T':
			add = _score * 1.5;
			break;
		case 'A':
			add = _score * 1.0;
			break;
		case 'B':
			add = _score / 1.5;
			break;
		}
		check1[_name] += add;
		check2[_name]++;
	}
	vector<school> re;
	for (unordered_map<string, double>::iterator it = check1.begin(); it != check1.end(); it++) {
		string _name = it->first;
		re.push_back(school(_name, check1[_name], check2[_name]));
	}
	sort(re.begin(), re.end());
	int len = re.size();
	int cnt = 1;
	printf("%d\n", len);
	printf("%d %s %d %d\n", cnt, re[0].name.c_str(), re[0].score_i, re[0].num);
	for (int i = 1; i < len; i++) {
		if (re[i].score_i != re[i - 1].score_i)
			cnt = i + 1;
		printf("%d %s %d %d\n", cnt, re[i].name.c_str(), re[i].score_i, re[i].num);
	}
	return 0;
}