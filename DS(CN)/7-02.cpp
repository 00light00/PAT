#include<bits/stdc++.h>
using namespace std;

struct poly {
	vector<pair<int, int> > po;
	poly() {};
	poly(int ex, int co) {
		po.push_back(make_pair(ex, co));
	}
	poly operator+(poly op) {
		poly re;
		auto p = po.begin(), pop = op.po.begin();
		while (p != po.end() && pop != op.po.end()) {
			if (p->second > pop->second)
				re.po.push_back(*p++);
			else if (p->second < pop->second)
				re.po.push_back(*pop++);
			else {
				if (p->first + pop->first)
					re.po.push_back(make_pair(p->first + pop->first, p->second));
				p++;
				pop++;
			}
		}
		while (p != po.end()) {
			if(p->first)
				re.po.push_back(*p);
			p++;
		}
		while (pop != op.po.end()) {
			if(pop->first)
				re.po.push_back(*pop);
			pop++;
		}
		if (re.po.empty())
			re.po.push_back(make_pair(0, 0));
		return re;
	}
	poly operator*(poly op) {
		poly re;
		auto p = po.begin();
		while (p != po.end()) {
			poly add;
			auto pop = op.po.begin();
			while (pop != op.po.end()) {
				if(p->first*pop->first)
					add.po.push_back(make_pair(p->first*pop->first, p->second + pop->second));
				pop++;
			}
			if (re.po.empty())
				re = add;
			else
				re = re + add;
			p++;
		}
		if (re.po.empty())
			re.po.push_back(make_pair(0, 0));
		return re;
	}
	void print() {
		auto p = po.begin();
		while (p != po.end()) {
			if (p != po.begin())
				printf(" ");
			printf("%d %d", p->first, p->second);
			p++;
		}
		printf("\n");
	}
};

int main() {
	poly A, B;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int ex, co;
		scanf("%d %d", &ex, &co);
		A.po.push_back(make_pair(ex, co));
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int ex, co;
		scanf("%d %d", &ex, &co);
		B.po.push_back(make_pair(ex, co));
	}


	poly readd = A + B;
	poly replus = A * B;
	replus.print();
	readd.print();
	return 0;
}