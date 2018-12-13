#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct student
{
	int id_num;
	int de;
	int cai;

};

const int MAX = 100010;
vector<student> st1, st2, st3, st4;

struct comp
{
	bool operator()(student st1, student st2) {
		if (st1.de + st1.cai != st2.de + st2.cai) {
			return st1.de + st1.cai > st2.de + st2.cai;
		}
		else {
			if (st1.de != st2.de) {
				return st1.de > st2.de;
			}
			else {
				return st1.id_num < st2.id_num;
			}
		}
	}
};


int main() {
	int n, l, h;
	scanf("%d %d %d", &n, &l, &h);
	
	for (int i = 0;i < n;i++) {
		student tmp;
		scanf("%d %d %d", &tmp.id_num, &tmp.de, &tmp.cai);
		if (tmp.de >= l && tmp.cai >= l) {
			if (tmp.de >= h && tmp.cai >= h) {
				st1.push_back(tmp);
			}
			else if (tmp.de >= h) {
				st2.push_back(tmp);
			}
			else if (tmp.de >= tmp.cai) {
				st3.push_back(tmp);
			}
			else {
				st4.push_back(tmp);
			}
		}

	}

	sort(st1.begin(), st1.end(), comp());
	sort(st2.begin(), st2.end(), comp());
	sort(st3.begin(), st3.end(), comp());
	sort(st4.begin(), st4.end(), comp());
	printf("%d\n", st1.size() + st2.size() + st3.size() + st4.size());
	vector<student>::iterator it;
	for (it = st1.begin();it != st1.end();it++)
		printf("%08d %d %d\n", it->id_num, it->de, it->cai);
	for (it = st2.begin();it != st2.end();it++)
		printf("%08d %d %d\n", it->id_num, it->de, it->cai);
	for (it = st3.begin();it != st3.end();it++)
		printf("%08d %d %d\n", it->id_num, it->de, it->cai);
	for (it = st4.begin();it != st4.end();it++)
		printf("%08d %d %d\n", it->id_num, it->de, it->cai);
	return 0;
}