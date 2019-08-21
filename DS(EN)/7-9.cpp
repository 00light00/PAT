#include <bits/stdc++.h>
using namespace std;



map<char, int> code;

struct node {
	char value;
	node* child[2];
	node(char v = 0) :value(v) {
		child[0] = child[1] = NULL;
	}
};



int huffman(int n) {
	queue<int> que;
	vector<int> num;
	for (auto it = code.begin(); it != code.end(); ++it)
		num.push_back(it->second);
	sort(num.begin(), num.end(), greater<int>());
	n--;
	int p = n, re = 0;
	while (n) {
		int top = 0, now = 0;
		for (int i = 0; i < 2; ++i) {
			if (p < 0 || (!que.empty() && que.front() < num[p])) {
				top = que.front();
				que.pop();
			}
			else
				top = num[p--];
			now += top;
		}
		re += now;
		que.push(now);
		n--;
	}

	return re;
}

int insert(node* root, char v, char* cd) {
	int re = 0;
	int ch = *cd - '0';
	if (cd[0]) {
		if (root->value)
			re++;
		if (!root->child[ch])
			root->child[ch] = new node;
		re = insert(root->child[ch], v, cd + 1);
	}
	else {
		if (!root->value && !root->child[0] && !root->child[1])
			root->value = v;
		else
			re++;
	}

	return re;
}

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i) {
		char a[2];
		int cnt;
		scanf("%s %d", a, &cnt);
		code[a[0]] = cnt;
	}

	int wpl = huffman(n);

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		node* root = new node;
		int len = 0, cnt = 0;
		for (int j = 0; j < n; ++j) {
			char c[2], cd[66];
			scanf("%s %s", c, cd);
			cnt += insert(root, c[0], cd);
			len += (strlen(cd)) * code[c[0]];
		}
		if (cnt == 0 && len == wpl)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}