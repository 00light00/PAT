#include<bits/stdc++.h>
using namespace std;

struct score {
	string id;
	int program, mid, final, grade;
	score(string st = "", int p = -1, int m = -1, int f = -1, int g = 0) :id(st), program(p), mid(m), final(f), grade(g) {};
	bool operator<(score op) const {
		return grade != op.grade ? grade > op.grade : id < op.id;
	}
};

int main() {
	int p, m, n;
	scanf("%d %d %d", &p, &m, &n);
	map<string, score> student;
	for (int i = 0; i < p; i++) {
		char id[30];
		int score;
		scanf("%s %d", id, &score);
		student[id].program = score;
		student[id].id = id;
	}
	for (int i = 0; i < m; i++) {
		char id[30];
		int score;
		scanf("%s %d", id, &score);
		student[id].mid = score;
		student[id].id = id;
	}
	for (int i = 0; i < n; i++) {
		char id[30];
		int score;
		scanf("%s %d", id, &score);
		student[id].final = score;
		student[id].id = id;
	}
	set<score> re;

	for (auto it = student.begin(); it != student.end(); it++) {
		string id = it->first;
		score tmp = it->second;
		double grade = 0.5;
		if (tmp.program >= 200) {
			if (tmp.mid > tmp.final)
				grade += tmp.mid*0.4 + tmp.final*0.6;
			else
				grade += tmp.final;

			tmp.grade = grade;
			if (tmp.grade >= 60)
				re.insert(tmp);
		}
	}

	for (auto it = re.begin(); it != re.end(); it++) {
		printf("%s %d %d %d %d\n", it->id.c_str(), it->program, it->mid, it->final, it->grade);
	}
	return 0;
}