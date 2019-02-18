#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;
int pre[MAX], in[MAX], post[MAX];
void postorder(int prel, int inl, int postl, int n);

int main() {
	int n;
	scanf("%d", &n);
	stack<int> st;
	int id_pre = 0, id_in = 0;
	for (int i = 0; i < 2 * n; i++) {
		char comm[MAX];
		int ind;
		scanf("%s", comm);
		if (comm[1] == 'u') {
			scanf("%d", &ind);
			st.push(ind);
			pre[id_pre++] = ind;
		}
		else if (comm[1] == 'o') {
			ind = st.top();
			st.pop();
			in[id_in++] = ind;
		}
	}
	postorder(0, 0, 0, n);
	for (int i = 0; i < n; i++) {
		if (i > 0)
			printf(" ");
		printf("%d", post[i]);
	}
	return 0;
}

void postorder(int prel, int inl, int postl, int n) {
	if (n == 0)
		return;
	if (n == 1) {
		post[postl] = pre[prel];
		return;
	}
	int root = pre[prel];
	post[postl + n - 1] = root;
	int i = 0;
	for (i = 0; i < n; i++) {
		if (in[inl + i] == root)
			break;
	}

	int l = i, r = n - 1 - l;
	postorder(prel + 1, inl, postl, l);
	postorder(prel + l + 1, inl + l + 1, postl + l, r);
}