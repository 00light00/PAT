#include <bits/stdc++.h>
using namespace std;

struct node {
	string name;
	int prior;
	vector<node> child;
	node(string s, int p = 0) :name(s), prior(p) {};
	bool operator<(node op)const {
		return prior == op.prior ? name < op.name : prior > op.prior;
	}
};

void insert(node& root, const string& st) {
	int p = 0;
	while (st[p]&&st[p] != '\\')p++;
	string now = st.substr(0, p);
	int pos = 0;
	for (; pos < root.child.size(); pos++) {
		if (root.child[pos].name == now)
			break;
	}
	if (pos == root.child.size()) {
		int pri = 0;
		if (st[p] == '\\')
			pri = 1;
		root.child.push_back(node(now, pri));
	}
	if (p + 1 < st.size())
		insert(root.child[pos], st.substr(p + 1));
}

void print(node& root, const string& prefix) {
	cout << prefix << root.name << endl;
	sort(root.child.begin(), root.child.end());
	string pre = prefix + "  ";
	for (auto it = root.child.begin(); it != root.child.end(); ++it) {
		print(*it, pre);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	string st;
	getchar();
	node root("root");
	for (int i = 0; i < n; ++i) {
		getline(cin, st);
		insert(root, st);
	}

	print(root, "");
	return 0;
}