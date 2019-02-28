#include<bits/stdc++.h>
using namespace std;

const int MAX = 10010;
struct node {
	int ccnt, id;
	double area,estate;
	node(double e = 0, double a = 0, int c = 1) :estate(e), area(a), ccnt(c) {};
	bool operator<(node op)const {
		double av1 = area / ccnt;
		double av2 = op.area / op.ccnt;
		return fabs(av1 - av2) > 1e-5 ? av1 > av2 : id < op.id;
	}
};
node family[MAX];
vector<int> root(MAX, -1);

int find(int r) {
	int rt = r;
	if (root[rt]>=0) {
		while (root[rt] >= 0) {
			rt = root[rt];
		}
		root[r] = rt;
	}
	return rt;
}

void joint(int r1, int r2) {
	int rt1 = find(r1), rt2 = find(r2);
	if (rt1 != rt2) {
		if (rt1 > rt2)
		swap(rt1, rt2);
		root[rt2] = rt1;
		family[rt1].ccnt += family[rt2].ccnt;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	map<int, node> fa;
	for (int i = 0; i < n; i++) {
		int id, fid, mid;
		scanf("%d %d %d", &id, &fid, &mid);
		if (fid > 0) {
			joint(fid, id);
		}
		if (mid > 0) {
			joint(mid, id);
		}

		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int child;
			scanf("%d", &child);
			joint(child, id);
		}
		scanf("%lf %lf", &family[id].estate, &family[id].area);
		fa[id] = family[id];
	}
	map<int ,node>re;
	for (auto it = fa.begin(); it != fa.end(); it++) {
		int id = it->first;
		node pnode = it->second;
		int rt = find(id);
		re[rt].area += pnode.area;
		re[rt].estate += pnode.estate;
		re[rt].id = rt;
		re[rt].ccnt = family[rt].ccnt;
	}

	set<node> ans;
	for (auto it = re.begin(); it != re.end(); it++) {
		ans.insert(it->second);
	}
	printf("%d\n", ans.size());
	for (auto it = ans.begin(); it != ans.end(); it++) {
		int id = it->id, cnt = it->ccnt;
		double area = it->area, estate = it->estate;
		printf("%04d %d %.3f %.3f\n", id, cnt, estate / cnt, area / cnt);
	}
	return 0;
}