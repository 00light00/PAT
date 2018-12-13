#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

struct person {
	string name;
	int height;
	person(char n[], int h) :name(n), height(h) {};
	person() {};
	bool operator>(const person& cmp)const {
		return height == cmp.height ? name < cmp.name : height > cmp.height;
	}
};

int main() {
	int n, k;
	vector<person> pp;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		char name_t[10];
		int height_t;
		scanf("%s %d", name_t, &height_t);
		pp.push_back(person(name_t, height_t));
	}

	sort(pp.begin(), pp.end(),greater<person>());
	vector<vector<person> > re;
	int line_total = n / k + n % k;
	int line_start = 0;
	for (int i = 0; i < k; i++) {
		vector<person> tmp(line_total);
		int p = line_total / 2;
		for (int j = line_start; j < line_start + line_total; j += 2) {
			tmp[p++] = pp[j];
		}
		p = line_total / 2 - 1;
		for (int j = line_start + 1; j < line_start + line_total; j += 2) {
			tmp[p--] = pp[j];
		}
		re.push_back(tmp);
		line_start += line_total;
		line_total = n / k;
	}

	for (int i = 0; i < k; i++) {
		int len = re[i].size();
		for (int j = 0; j < len; j++) {
			if (j > 0)
				printf(" ");
			printf("%s", re[i][j].name.c_str());
		}
		printf("\n");
	}
	return 0;
}