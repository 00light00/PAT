#include<bits/stdc++.h>
using namespace std;

struct stdu {
	string id;
	int pat, mid_term, final_term, total;
	stdu(string i, int p, int mid = -1, int fi = -1, int to = 0) :id(i), pat(p), mid_term(mid), final_term(fi), total(to) {};
	bool operator<(stdu cmp) {
		return total == cmp.total ? id<cmp.id : total>cmp.total;
	}
};

int main() {
	int p, m, n;
	scanf("%d %d %d", &p, &m, &n);
	map<string, int> student_map;
	vector<stdu> student;
	int cnt_st = 0;
	for (int i = 0; i < p; i++) {
		string id;
		int score;
		cin >> id >> score;
		if (score >= 200) {
			student_map[id] = cnt_st++;
			student.push_back(stdu(id,score));
		}
	}
	for (int i = 0; i < m; i++) {
		string id;
		int score;
		cin >> id >> score;
		if (score >= 0 && score <= 100 &&student_map.find(id) != student_map.end()) {
			student[student_map[id]].mid_term = score;
		}
	}
	for (int i = 0; i < n; i++) {
		string id;
		int score;
		cin >> id >> score;
		if (student_map.find(id) != student_map.end()) {
			student[student_map[id]].final_term = score;
			if (score >= 0 && score <= 100) {
				if (student[student_map[id]].mid_term <= score) {
					student[student_map[id]].total = score;
				}
				else {
					student[student_map[id]].total = score * 0.6 + student[student_map[id]].mid_term*0.4 + 0.5;
				}
			}
			
		}
	}
	sort(student.begin(), student.end());
	for (int i = 0; i < cnt_st; i++) {
		if (student[i].total >= 60)
			cout << student[i].id << " " << student[i].pat << " " << student[i].mid_term << " " << student[i].final_term << " " << student[i].total << endl;
	}
	return 0;
}